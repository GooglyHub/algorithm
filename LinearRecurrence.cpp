#include "LinearRecurrence.h"
#include "Matrix.h"

#include <vector>
#include <iostream>

using namespace std;

/*
  Example:
  f(0) = 5
  f(1) = 7
  f(2) = -3
  f(n) = f(n-1) + 10*f(n-2) - 4*f(n-3)
  Find f(100).

    You would pass in base = { 5, 7, -3 }, recur = { 1, 10, -4 }, k = 100, mod = 0
*/
template <class T>
T solveLinearRecurrence(vector <T> base, vector <T> recur, long long k, int mod)
{
    int N = base.size();
    Matrix <T> m(N, mod);
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (r == 0)
                m[r][c] = recur[c];
            else
                m[r][c] = (r == c+1);
        }
    }
    Matrix <T> mk = m.pow(k);
    T ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (mod == 0)
            ans += mk[N-1][i] * base[N-1-i];
        else
        {
            long long pr = mk[N-1][i];
            pr *= base[N-1-i];
            if (pr >= 0)
                pr %= mod;
            else
                pr = (pr % mod) + mod;
            ans = (T)((ans + pr) % mod);
        }
    }
    return ans;
}

int testLinearRecurrence()
{
    vector <int> base;
    base.push_back(5);
    base.push_back(7);
    base.push_back(-3);

    vector <int> recur;
    recur.push_back(1);
    recur.push_back(10);
    recur.push_back(-4);

    for (int i=0; i<=10; i++)
        cout << i << " " << solveLinearRecurrence(base, recur, i, 0) << endl;
}
