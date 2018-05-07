#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED

#include <iostream>
using namespace std;

class MyVector
{
public:
    MyVector();
    MyVector(int n);
    int get(int i) const;
    void set(int i, int x);
    int size();
    int capacity();
    void push_back(int x);
    void reserve(int n);

private:
    int sz;
    int space;
    int *arr;
};
#endif // MYVECTOR_H_INCLUDED