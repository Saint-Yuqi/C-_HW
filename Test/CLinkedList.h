#pragma once
#include"Alist.h"
#include<ostream>

struct Node 
{
	int data;
	Node* next;
	
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {};

	~Node() {};
};

class LinkedList  : public Alist
{
private:
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}
    LinkedList(const LinkedList& list);
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }		
    int& operator[](int index);
    bool indexValid(int index);		
    bool operator==(Alist& list1);		
    LinkedList& operator=(Alist& list);     
    void clear();
    void push_forward(int data);	
    void push_back(int data);
    void insert(int data, int index);	
    int extractHead();
    int extractTail();
    int extractElement(int index);
    void extract_by_value(int value);
    void combine_list(LinkedList& list);
		

    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
    {
        Node* temp = list.head;
        stream << "[" << list.count << "]:{ ";
        while (temp != nullptr)
        {
        stream << temp->data << " ";
        temp = temp->next;
        }
        stream << "}";
        return stream;
        }
    };