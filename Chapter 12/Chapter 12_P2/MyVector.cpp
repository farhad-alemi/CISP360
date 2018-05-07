#include "MyVector.h"

MyVector::MyVector()
{
    sz = 0;
    space = 0;
    arr = nullptr;
}

MyVector::MyVector(int n)
{
    sz = n;
    space = n;
    arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

int MyVector::get(int i) const
{
    return arr[i];
}

void MyVector::set(int i, int x)
{
    arr[i] = x;
}

int MyVector::size()
{
    return sz;
}

int MyVector::capacity()
{
    return space;
}

void MyVector::push_back(int x)
{
    if (sz == 0)
    {
        MyVector::reserve(1);
    }
    else if (sz == space)
    {
        MyVector::reserve(2 * space);
    }
    sz++;
    arr[sz - 1] = x;
}

void MyVector::reserve(int n)
{
    int temp_array [n];
    
    for (int i = 0; i < n; i++)
    {
        if (i < sz)
        {
            temp_array[i] = arr[i];
        }
        else
        {
            temp_array[i] = 0;
        }
    }
    delete arr;
    arr = temp_array;
    space = n;
}