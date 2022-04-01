#pragma once
#include"Alist.h"
#include<ostream>

class CArraylist : public Alist
{
public:
 	CArraylist(int capacity = 0) : count(0), capacity(capacity), data(new int[capacity]) {}
	CArraylist(const CArraylist& list);
	~CArraylist()
	{
		delete[] this->data;
	}

    CArraylist& operator+= (Alist&);
    CArraylist& operator= (Alist&);
    virtual bool operator==(Alist&);
    virtual bool isSorted();

	void push_back(int value);
    void push_forward(int value);
    void extract_by_index(int value);
    void extract_by_value(int value);
    void insert_by_index(int value, int index);
    CArraylist& combine_arraylist(CArraylist&);
    void quickSort();

	friend std::ostream& operator<< (std::ostream& stream, const CArraylist& list)
    {
    	stream << "[" << list.count << "/" << list.capacity << "] { ";
        for (int i = 0; i < list.count; ++i)
		{
			stream << list.data[i] << " ";
		}
		stream << "}" << std::endl;
        return stream;
    }

private:
	int count;
    int capacity;
    int* data;
	void expand(int expandRate = 0);
	void assignArraylist(const CArraylist& list);
};