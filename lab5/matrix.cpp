#include "matrix.h"
vector<vector<float>> GetMatrix(vector<vector<float>> m, int i, int j) {
    vector<vector<float>> newMatrix;
    vector<float> row(m.size() - 1);
    int o = 0;

    for (int l = 0; l < m.size(); l++) {
        if (l == i) continue;
        row.assign(m.size() - 1, 0);
        for (int k = 0; k < m.size(); k++) {
            if (k == j) continue;
            row[o] = m[l][k];
            o++;
        }
        newMatrix.push_back(row);
        row.clear();
        o = 0;
    }

    return newMatrix;
}


float Det(vector<vector<float>> m) {

    float d = 0;

    int size = m.size();
    int c = 1;

    if (size == 1) {
        return m[0][0];
    }

    if (size == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    if (size >= 3) {
        for (int j = 0; j < size; j++) {
            d += m[0][j] * c * Det(GetMatrix(m, 0, j));
            c = -c;
        }
    }

    return d;

}

float Matrix::Determinator() {
    return Det(matrix);
}

float Matrix::Nor() {
    float max = 0;
    for (int i = 0; i < matrix.size(); i++) {
        float buff = 0;
        for (int k = 0; k < matrix[i].size(); k++) {
            buff += matrix[i][k];
        }
        if (buff > max)
            max = buff;
    }
    return max;
}

Matrix::Matrix(int X, int Y) {
    int elem;
    vector<float> row;
    for (int k = 0; k < X; k++) {
        for (int i = 0; i < Y; i++) {
            cin >> elem;
            row.push_back(elem);
        }
        matrix.push_back(row);
        row.clear();
    }
    rows = Y;
    columns = X;
    det = Determinator();
    nor = Nor();
}

void Matrix::make (vector<float> n, int X, int Y) {
    matrix.push_back(n);
    rows = Y;
    columns = X;
    det = Determinator();
    nor = Nor();
}


Matrix operator^(const Matrix &matrix_a, int value)
{
    Matrix pr = matrix_a;
    int i = 1;
    if (matrix_a.columns == matrix_a.rows)
    {
        while (i < value)
        {
            pr *= matrix_a;
            i++;

        }

        pr.det = pr.Determinator();
        pr.nor = pr.Nor();
        return pr;
    }
    else cout << "vozvedenie nevozmijno\n";
    return pr;
}

Matrix operator^=(Matrix &matrix_a, int value)
{
    Matrix old_a = matrix_a;
    int i = 1;
    if (matrix_a.columns == matrix_a.rows)
    {
        while (i < value)
        {
            matrix_a *= old_a;
            i++;

        }
        return matrix_a;
    }
    else cout << "vozvedenie nevozmijno\n";
    return 0;
}

Matrix operator*(const Matrix &matrix_a, const  Matrix &matrix_b)
{
    vector<float> colum;
    float col = 0;
    Matrix pr;
    if (matrix_a.rows == matrix_b.columns)
    {
        for (int i = 0; i < matrix_a.columns; i++)
        {
            for (int j = 0; j < matrix_b.rows; j++)
            {
                for (int k = 0; k < matrix_a.rows; k++)
                {
                    col += matrix_a.matrix[i][k] * matrix_b.matrix[k][j];
                }
                colum.push_back(col);
                col = 0;
            }
            pr.matrix.push_back(colum);
            colum.clear();
        }
        pr.columns = matrix_b.columns;
        pr.rows = matrix_a.rows;
        pr.det = pr.Determinator();
        pr.nor = pr.Nor();
        return pr;
    }
    else cout << "proizvedenie nevozmojno\n";
    return pr;
}

Matrix operator*=(Matrix &matrix_a, const  Matrix &matrix_b)
{
    vector<float> colum;
    float col = 0;
    Matrix pr;
    if (matrix_a.rows == matrix_b.columns)
    {
        for (int i = 0; i < matrix_a.columns; i++)
        {
            for (int j = 0; j < matrix_b.rows; j++)
            {
                for (int k = 0; k < matrix_a.rows; k++)
                {
                    col += matrix_a.matrix[i][k] * matrix_b.matrix[k][j];
                }
                colum.push_back(col);
                col = 0;
            }
            pr.matrix.push_back(colum);
            colum.clear();
        }
        matrix_a.matrix = pr.matrix;
        matrix_a.rows = matrix_b.rows;
        matrix_a.det = matrix_a.Determinator();
        matrix_a.nor = matrix_a.Nor();
        return matrix_a;
    }
    else cout << "proizvedenie nevozmojno\n";
    return pr;
}

Matrix operator-(const Matrix& matrix_a, const Matrix& matrix_b) {
    Matrix m = matrix_a;
    if (matrix_a.rows != matrix_b.rows || matrix_a.columns != matrix_b.columns) return m;
    for (int i = 0; i < matrix_a.rows; i++) {
        for (int k = 0; k < matrix_a.columns; k++) {
            m.matrix[k][i] = matrix_a.matrix[k][i] - matrix_b.matrix[k][i];
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}
Matrix operator-=(Matrix& matrix_a, const Matrix& matrix_b) {
    if (matrix_a.rows != matrix_b.rows || matrix_a.columns != matrix_b.columns) return matrix_a;
    for (int i = 0; i < matrix_a.rows; i++) {
        for (int k = 0; k < matrix_a.columns; k++) {
            matrix_a.matrix[k][i] -= matrix_b.matrix[k][i];
        }
    }
    matrix_a.det = matrix_a.Determinator();
    matrix_a.nor = matrix_a.Nor();
    return  matrix_a;
}
Matrix operator*(const Matrix &matrix_a, int value) {
    Matrix pr = matrix_a;
    for (int i = 0; i < matrix_a.rows; i++) {
        for (int j = 0; j < matrix_a.columns; j++) {
            pr.matrix[j][i] *= value;
        }
    }
    pr.det = pr.Determinator();
    pr.nor = pr.Nor();
    return pr;
}
Matrix operator*=(Matrix &matrix_a, int value) {

    for (int i = 0; i < matrix_a.rows; i++) {
        for (int j = 0; j < matrix_a.columns; j++) {
            matrix_a.matrix[j][i] *= value;
        }
    }
    matrix_a.det = matrix_a.Determinator();
    matrix_a.nor = matrix_a.Nor();
    return matrix_a;
}

void Matrix::printMatrix() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int k = 0; k < matrix[i].size(); k++) {
            cout << matrix[i][k] << " ";
        }
        cout << std::endl;
    }
}

vector <vector<float>> Matrix::getMatrix() const {
    return matrix;
}

Matrix operator/(const Matrix& left, const int& right) {
    Matrix m = left;
    for (int i = 0; i < m.rows; i++) {
        for (int k = 0; k < m.columns; k++) {
            m.matrix[i][k] /= right;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

Matrix operator/=(Matrix& left, const int& right) {
    for (int i = 0; i < left.rows; i++) {
        for (int k = 0; k < left.columns; k++) {
            left.matrix[i][k] /= right;
        }
    }
    left.det = left.Determinator();
    left.nor = left.Nor();
    return left;
}

Matrix operator+(const Matrix& left, const Matrix& right) {
    Matrix m = left;
    if (left.rows != right.rows || left.columns != right.columns) return m;
    for (int i = 0; i < left.rows; i++) {
        for (int k = 0; k < left.columns; k++) {
            m.matrix[i][k] = left.matrix[i][k] + right.matrix[i][k];
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

Matrix operator+=(Matrix& m, const Matrix& right) {
    if (m.rows != right.rows || m.columns != right.columns) return m;
    for (int i = 0; i < m.rows; i++) {
        for (int k = 0; k < m.columns; k++) {
            m.matrix[i][k] += right.matrix[i][k];
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

Matrix& operator++(Matrix& m) { //it is just preincrement
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            m.matrix[i][k]++;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

Matrix operator++(Matrix& m, int) { //it is just postincrement
    Matrix oldValue(m); //it just function fot pre
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            m.matrix[i][k]++;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

Matrix& operator--(Matrix& m) { //it is predecrement
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            m.matrix[i][k]--;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

Matrix operator--(Matrix& m, int) { //you must know what is it
    Matrix oldValue(m);
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            m.matrix[i][k]--;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

const Matrix operator+(const Matrix& m, const int& value) { //it is sum with value (value must be integer)
    Matrix buff = m;
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            buff.matrix[i][k] += value;
        }
    }
    buff.det = buff.Determinator();
    buff.nor = buff.Nor();
    return buff;
}

const Matrix operator+(const int& value, const Matrix& m) { //it is sum with value (value must be integer)
    Matrix buff = m;
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            buff.matrix[i][k] += value;
        }
    }
    buff.det = buff.Determinator();
    buff.nor = buff.Nor();
    return buff;
}

Matrix& operator+=(Matrix& m, const int& value) { //it is sum with value (value must be integer)
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            m.matrix[i][k] += value;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();
    return m;
}

const Matrix operator-(const Matrix& m, const int& value) { //it is difference with value (value must be integer)
    Matrix buff = m;
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            buff.matrix[i][k] -= value;
        }
    }
    buff.det = buff.Determinator();
    buff.nor = buff.Nor();
    return buff;
}

Matrix& operator-=(Matrix& m, const int& value) { //it is difference with value (value must be integer)
    for (int i = 0; i < m.columns; i++) {
        for (int k = 0; k < m.rows; k++) {
            m.matrix[i][k] -= value;
        }
    }
    m.det = m.Determinator();
    m.nor = m.Nor();

    return m;
}
float Matrix::GetDet() { return det; }
float Matrix::GetNor() { return nor; }
int Matrix::GetRow() { return rows; }
int Matrix::GetColum() { return columns; }
