#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyString
{
public:
    char* str;
    int size;
    MyString()
    {
        str = nullptr;
        size = 0;
    }
    MyString(char* st)
    {
        size = strlen(st);
        str = st;
    }

    MyString(string s)
    {
        str = new char[s.length() + 1];
        size = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            str[i] = s[i];
        }
        str[size] = '\0';
    }
    MyString(const MyString& other)
    {
        size = other.size;
        str = new char[other.size + 1];
        for (int i = 0; i < other.size; i++)
        {
            str[i] = other.str[i];
        }

    }
    ~MyString()
    {
        delete[] this->str;
    }

    MyString& operator = (const MyString& other)
    {
        size = other.size;

        if (str != nullptr)
        {
            delete[] str;
        }

        str = new char[other.size + 1];
        for (int i = 0; i < other.size; i++)
        {
            str[i] = other.str[i];
        }

        str[size] = '\0';
        return *this;
    }

    void Print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }

    void Mass(char* st)
    {
        size = strlen(st);
        if (str != nullptr)
        {
            delete[] str;
        }

        str = new char[size + 1];

        for (int i = 0; i < size; i++)
        {
            str[i] = st[i];
        }
        str[size] = '\0';
    }

    void in_file(const char z[])
    {
        if (str != nullptr)
        {
            delete[] this->str;
        }
        ifstream fin;
        string temp;
        fin.open(z);
        getline(fin, temp);

        size = temp.length();
        str = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            str[i] = temp[i];
        }
        str[size] = '\0';


        fin.close();
    }

    void out_file(const char z[])
    {
        ofstream fn;
        fn.open(z);
        for (int i = 0; i < this->size; i++)
        {
            fn << this->str[i];
        }
        fn.close();
    }
    void enter_string(string s)
    {
        size = s.length();
        if (str != nullptr)
        {
            delete[] this->str;
        }
        str = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            str[i] = s[i];
        }
        str[size] = '\0';
    }

};