#include "Matrix.h"

#include <iostream>

using namespace std;

template <class T>
Matrix<T>::Matrix(int rows, int mod = 0): N(rows), MOD(mod)
{
    a = new T*[N];
    for (int i = 0; i < N; i++) {
        a[i] = new T[N];
        for (int j = 0; j < N; j++)
            a[i][j] = 0;
    }
}

template <class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < N; i++)
        delete a[i];
    delete a;
}

template <class T>
int Matrix<T>::getSize()
{
    return N;
}

template <class T>
T* Matrix<T>::operator[](unsigned int i)
{
    return a[i];
}

template <class T>
ostream& operator<<(ostream& out, Matrix<T>& m)
{
    for (int r = 0; r < m.getSize(); r++)
    {
        for (int c = 0; c < m.getSize(); c++)
            out << m[r][c] << " ";
        out << endl;
    }
    return out;
}

// Assumes that the two matrices are of the same size!
template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& t)
{
    Matrix<T> *prod = new Matrix<T>(N, MOD);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
        {
            prod->a[r][c] = 0;
            for (int i = 0; i < N; i++)
            {
                if (MOD == 0)
                    prod->a[r][c] += a[r][i] * t.a[i][c];
                else
                {
                    long long x = a[r][i];
                    x *= t.a[i][c];
                    if (x >= 0)
                        x %= MOD;
                    else
                        x = (x % MOD) + MOD;
                    prod->a[r][c] += (T)x;
                    if (prod->a[r][c] >= MOD)
                        prod->a[r][c] -= MOD;
                }
            }
        }
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            a[r][c] = prod->a[r][c];
    delete prod;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::pow(long long p)
{
    // Return value initialized to the identity matrix
    Matrix<T> *res = new Matrix<T>(N, MOD);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            res->a[r][c] = (r==c);

    // temp will be the matrix raised to some power of 2
    Matrix<T> *temp = new Matrix<T>(N, MOD);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            temp->a[r][c] = a[r][c];

    while (p > 0)
    {
        if (p & 1)
            *res *= (*temp);
        p >>= 1;
        *temp *= (*temp);
    }
    delete temp;
    return *res;
}

int test_matrix()
{
    Matrix <int> m(2);
    m[0][0] = m[0][1] = m[1][0] = 1;
    cout << m;

    Matrix <int> mm = m.pow(20);
    cout << mm;

    return 1;
}
