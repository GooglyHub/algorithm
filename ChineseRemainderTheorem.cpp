#include "ChineseRemainderTheorem.h"

#include <vector>
#include <iostream>

using namespace std;

template <class T>
T chineseRemainderTheorem(const vector <T> &a, const vector <T> &m)
{
    vector <T> u = chineseRemainderTheoremHelper(m);
    T ans = 0, M = 1;
    for (unsigned int i = 0; i < u.size(); i++)
    {
        ans += a[i] * u[i];
        M *= m[i];
    }
    while (ans < 0)
        ans += M;
    return ans % M;
}

template <class T>
vector <T> chineseRemainderTheoremHelper(const vector <T> &m)
{
    vector <T> ret;
    T prod = 1;
    for (unsigned int i = 0; i < m.size(); i++)
        prod *= m[i];
    for (unsigned int i = 0; i < m.size(); i++)
        ret.push_back(euclid(m[i], prod/m[i]));
    return ret;
}

// Returns a number x such that x%m1==1 and x%m2==0
template <class T>
T euclid(T m1, T m2)
{
    T s = 0, ss = 1, t = 1, tt = 0, r = m2, rr = m1;
    while (r)
    {
        T q = rr / r;
        T v;
        v = r; r = rr - q*r; rr = v;
        v = s; s = ss - q*s; ss = v;
        v = t; t = tt - q*t; tt = v;
    }
    return tt * m2;
}

int test_crt()
{
    // Solve x==2 (mod 3), x==3 (mod 4), x==1 (mod 5)
    vector <int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(1);

    vector <int> m;
    m.push_back(3);
    m.push_back(4);
    m.push_back(5);

    cout << chineseRemainderTheorem(a, m);
    return 1;
}

