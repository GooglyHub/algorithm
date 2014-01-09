#ifndef CHINESEREMAINDERTHEOREM_H_INCLUDED
#define CHINESEREMAINDERTHEOREM_H_INCLUDED

#include <vector>

using namespace std;

template <class T>
T chineseRemainderTheorem(const vector <T> &a, const vector <T> &m);

template <class T>
vector <T> chineseRemainderTheoremHelper(const vector <T> &m);

template <class T>
T euclid(T m1, T m2);

#endif // CHINESEREMAINDERTHEOREM_H_INCLUDED
