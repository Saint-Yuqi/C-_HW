#pragma once

class Alist
{
public:
    virtual ~Alist() = 0;
    //operators
    virtual Alist& operator<< (Alist&) = 0;
    virtual Alist& operator+= (Alist&) = 0;
    virtual Alist& operator= (Alist&) = 0;
    virtual  bool operator==(Alist&) = 0;
    virtual  bool isSorted() = 0;
    //methods
    virtual void push_back(int value) = 0;
    virtual void push_forward(int value) = 0;
    virtual void extract_by_index(int value) = 0;
    virtual void extract_by_value(int value) = 0;
    virtual void insert_by_index(int value, int index) = 0;
    virtual Alist& combine_arraylist(Alist&) = 0;
    virtual void quickSort() = 0;

};
