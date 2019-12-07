#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
#pragma once
#ifndef A
#define A
class Matrix {
private:

    vector<vector<float>> matrix;
    int rows, columns;

    float det, nor;

protected:

    float Determinator();

    float Nor();

public:
    Matrix(int X = 0, int Y = 0);

    friend Matrix operator^(const Matrix &matrix_a, int value);

    friend Matrix operator^=(Matrix &matrix_a, int value);

    friend Matrix operator*(const Matrix &matrix_a, const  Matrix &matrix_b);

    friend Matrix operator*=(Matrix &matrix_a, const  Matrix &matrix_b);

    friend Matrix operator-(const Matrix& matrix_a, const Matrix& matrix_b);

    friend Matrix operator-=(Matrix& matrix_a, const Matrix& matrix_b);

    friend Matrix operator*(const Matrix &matrix_a, int value);

    friend Matrix operator*=(Matrix &matrix_a, int value);

    void printMatrix();
    float GetDet();
    float GetNor();
    int GetRow();
    int GetColum();

    friend Matrix operator/(const Matrix& left, const int& right);

    friend Matrix operator/=(Matrix& left, const int& right);

    friend Matrix operator+(const Matrix& left, const Matrix& right);

    friend Matrix operator+=(Matrix& left, const Matrix& right);

    friend Matrix& operator++(Matrix& m);

    friend Matrix operator++(Matrix& m, int);

    friend Matrix& operator--(Matrix& m);

    friend Matrix operator--(Matrix& m, int);

    friend const Matrix operator+(const Matrix& m, const int& value);

    friend const Matrix operator+(const int& value, const Matrix& m);

    friend Matrix& operator+=(Matrix& m, const int& value);

    friend const Matrix operator-(const Matrix& m, const int& value);

    friend Matrix& operator-=(Matrix& m, const int& value);

};

#endif // !1
