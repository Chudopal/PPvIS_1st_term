#ifndef HUMAN_H
#define HUMAN_H


class human
{
public:
    human(int);
    human();
    int getValue() const;
    bool operator > (human);
    bool operator < (human);
    bool operator == (human);
    void operator = (human &);
    int operator + (human);
    int operator / (int);
    int operator [] (int);
private:
    int value;
};

#endif // HUMAN_H
