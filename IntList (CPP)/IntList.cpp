#include <iostream>
#include <stdio.h>
#include "IntList.h"

using namespace std;


//构造函数
IntList::IntList(int numVals  , int val)
{
    if (numVals > 0)
    {
        numberValues = numVals;
        values = new int [numVals];
        for (int i = 0 ; i < numVals ; ++i)
            values[i] = val;
    }
    else
    {
        numberValues = 0;
        values = NULL;
    }
}

//拷贝函数
IntList::IntList(const IntList &il)
{
    numberValues = il.size();
    if (numberValues > 0)
    {
        values = new int [numberValues];
        for (int i = 0 ; i < numberValues ; i++)
            values[i] = il.values[i];
    }
}

//析构函数
IntList::~IntList()
{
    delete [] values;
    numberValues = 0;
    values = NULL;
}

//运算符重载
IntList& IntList::operator=(const IntList &il)
{
    if (this != &il)
    {
        numberValues = il.size();
        delete [] values;
        values = NULL;
        if (numberValues > 0)
        {
            values = new int [numberValues];
            for (int i = 0 ; i < numberValues ; i++)
                values[i] = il.values[i];
        }
    }
}


//SIZE函数
int IntList::size() const
{
    return this -> numberValues;
}

//RESIZE函数
void IntList::resize (int n  , int val )
{
    if (n <= 0)
    {
        numberValues = 0;
        delete [] values;
        values = NULL;
    }
    else
    {
        if (n > numberValues)
        {
            int *dva;
            dva = new int [n];
            for (int i = 0 ; i < numberValues ; i++)
                dva[i] = values[i];
            for (int j = numberValues ; j < n  ; j++)
                dva[j] = val;
            numberValues = n;
            values = new int [n];
            for (int k = 0 ; k < n ; k++)
                values[k] = dva[k];
            delete [] dva;
        }
        else
        {
            int *dva;
            dva = new int [n];
            for (int i = 0 ; i < n ; i++)
                dva[i] = values[i];
            numberValues = n;
            values = new int [n];
            for (int i = 0 ; i < n ; i++)
                values[i] = dva[i];
            delete [] dva;
        }

    }
}

//PUSH-BACK操作函数
void IntList::push_back (int val)
{
    if(this != NULL)
    {
        int *dva;
        dva = new int [numberValues + 1];
        for (int i = 0 ; i < numberValues ; i++)
            dva[i] = values[i];
        dva[numberValues] = val;
        numberValues = numberValues + 1;
        values = new int [numberValues];
        for (int i = 0 ; i < numberValues ; i++)
            values[i] = dva[i];
        delete [] dva;
    }
    else
    {
        values = new int [1];
        values[0] = val;
        numberValues = 1;
    }
}

//PRINT结果
void IntList::print()
{
    if (values != NULL)
    {
        if (numberValues > 1)
        {
            cout << numberValues << ":";
            for (int i = 0 ; i < numberValues - 1; i++)
                cout << values[i] << " ";
            cout << values[numberValues - 1] << endl;
        }
        else if(numberValues == 1)
        {
            cout << numberValues << ":";
            cout << values[0] << endl;
        }
    }
    else
    {
        cout << numberValues << ":" << endl;
    }
}

int main()
{
    std::cout << "Your Student No. and Name" << std::endl;
    IntList a(5 , 1);
    std::cout << "a(5,1)" << std::endl;
    a.print();
    a.resize(6,2);
    std::cout << "a.resize(6,2)" << std::endl;
    a.print();
    a.resize(4,2);
    std::cout << "a.resize(4,2)" << std::endl;
    a.print();
    IntList b;
    std::cout << "b" << std::endl;
    b.print();
    a=b;
    std::cout << "a=b" << std::endl;
    a.print();
    b.print();
    b.push_back(2);
    std::cout << "b.push_back(2)" << std::endl;
    a.print();
    b.print();
    b=b;
    std::cout << "b=b" << std::endl;
    a.print();
    b.print();
    b=a;
    std::cout << "b=a" << std::endl;
    a.print();
    b.print();
    b.push_back(2);
    std::cout << "b.push_back(2)" << std::endl;
    a.print();
    b.print();
    std::cout << "Program ended with exit code: 0" << std::endl;

    return 0;
}
