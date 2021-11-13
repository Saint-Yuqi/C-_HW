#include<iostream>
#include<string>

using namespace std;

class Arraylist
{
private:
        int count;
        int capacity;
        int* data;

        void expand(int expandRate = 0)
	    {
		    if (expandRate == 0)
            {
                expandRate = capacity;
            }
            int* newData = new int[capacity + expandRate];
            for (int i = 0; i < count; ++i)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity += expandRate;
	    }

        void assignArraylist(const Arraylist& list)
        {
            this->capacity = list.capacity;
            this->count = list.count;
            this->data = new int[list.count];
            for (int i = 0; i < list.count; ++i)
            {
                this->data[i] = list.data[i];
            }
        }
public:
        Arraylist(int capacity = 0) : count(0), capacity(capacity), data(new int[capacity]) {}

        Arraylist(const Arraylist& list)
        {
            assignArraylist(list);
        }

        ~Arraylist()
	    {
		    delete[] this->data;
	    }

        //operators
        friend ostream& operator<< (ostream& stream, const Arraylist& list)
        {
            stream << "[" << list.count << "/" << list.capacity << "] { ";
            for (int i = 0; i < list.count; ++i)
		    {
			    cout << list.data[i] << " ";
		    }
		    stream << "}" << endl;
            return stream;
        }

        bool operator==(Arraylist& list)
        {
            if (list.count != count)
            {
                return false;
            }
            for (int i = 0; i < count; ++i)
            {
                if (list.data[i] != data[i])
                {
                    return false;
                }
            }
            return true;
        }

        Arraylist& operator+= (Arraylist& list)
        {
           combine_arraylist(list);
           return (*this);
        }
        Arraylist& operator=(Arraylist& list)
        {
            delete[] this->data;
            assignArraylist(list);    
            return *this;
        }

        //methods
        void push_back(int value)
	    {
		    if (count == capacity)
		    {
			    expand();
		    }
		    data[count] = value;
		    ++count;
	    }

        void push_forward(int value)
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

        void extract_by_index(int value)
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

        void extract_by_value(int value)
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

        void insert_by_index(int value, int index)
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
        
        Arraylist combine_arraylist(Arraylist& list)
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
};

int main(int argc, char* argv[])
{
    Arraylist list1(2);
    Arraylist list2(3);
    list1.push_back(1);
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    /*if(list1 == list2)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    */
    //list1 = list2;
    
    cout << list1 << endl; 
    list1.push_back(2);
    list1.push_back(2);   
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(2);
    list1.push_back(3);
    cout << list1 << endl;
    list1.extract_by_value(2);
    cout << list1 << endl;
    list1.insert_by_index(2,5);
    cout << list1 << endl;
    cout << list2 << endl;
    list1.combine_arraylist(list2);
    list1+=list1;
    cout << list1 << endl;

    return EXIT_SUCCESS;
}