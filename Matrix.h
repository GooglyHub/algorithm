#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <class T>
class Matrix
{
    public:
        Matrix(int rows, int mod);
        ~Matrix();
        int getSize();
        T* operator[](unsigned int i);
        Matrix& operator*=(const Matrix& t);
        Matrix& pow(long long p);

    protected:
        int N;
        int MOD;
        T **a;
};

#endif // MATRIX_H
