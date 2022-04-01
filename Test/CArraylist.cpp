#include "CArraylist.h"

void CArraylist::assignArraylist(const CArraylist& list)
{
    capacity = list.capacity;
    count = list.count;
    data = new int[list.count];
    for (int i = 0; i < list.count; ++i)
    {
        data[i] = list.data[i];
    }
}

CArraylist &CArraylist::combine_arraylist(CArraylist& list)
{
    int length = list.count;
    if (capacity < count + list.count)
    {
        expand(count + list.count - capacity + 1);
    }

    for (int i = 0; i < length; ++i)
    {
        push_back(list.data[i]);
    }

    return (*this);
}

CArraylist::CArraylist(const CArraylist& list)
{
   assignArraylist(list);
}

CArraylist &CArraylist::operator+= (CArraylist& list)
{
    combine_arraylist(list);
    return (*this);
}

CArraylist &CArraylist::operator= (CArraylist& list)
{
    delete[] this->data;
    assignArraylist(list);    
    return *this;
}

bool CArraylist::isSorted()
{
    for (int i = 0; i < count - 1; ++i)
	{
		if (data[i] > data[i + 1])
		{
			return false;
		}
	}
	return true;
}

void CArraylist::push_back(int value)
{
    if (count == capacity)
		{
			expand();
		}
		data[count] = value;
		++count;
}

void CArraylist::push_forward(int value)
{
    if (count == capacity)
        {
            expand();
        }
        for (int i = count; i > 0; --i)
        {
            data[i] = data[i - 1];
        }
        ++count;
        data[0] = value;
}

void CArraylist::extract_by_index(int value)
    {
        int* newData = new int[capacity];
        for (int i = 0; i < count - 1; ++i)
        {
            if (i >= value)
            {
                newData[i] = data[i + 1];
            }
            else
            {
                newData[i] = data[i];
            }
            }
            delete[] data;
            data = newData;
            --count;
        }

void CArraylist::extract_by_value(int value)
    {
        if (count <= 0)
        {
            return;
        }

        for (int t = 0; t < count; t++)
        {                  
            if (data[t] == value)
            {
                extract_by_index(t);
                extract_by_value(value);  
            }                                
        }
    }

void CArraylist::insert_by_index(int value, int index)
    {
        int* newData = new int[capacity];
        for (int i = 0; i < count + 1; ++i)
        {
            if (i < index)
            {
                newData[i] = data[i];
            }
            else if (i == index)
            {
                newData[i] = value;
            }
            else if (i > index)
            {
                newData[i] = data[i - 1];
            }
                
        }
        delete[] data;
        data = newData;
        ++count;
    }
        
