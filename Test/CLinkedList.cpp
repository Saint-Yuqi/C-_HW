#include "CLinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
    Node* temp = list.head;
    while (temp != nullptr)
	{
        push_back(temp->data);
		temp = temp->next;
    }
}

int &LinkedList::operator[](int index)
{
	if (index < 0)
	{
		push_forward(0);
		return head->data;
	}
	if (index >= count)
	{
		push_back(0);
		return tail->data;
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

bool LinkedList::indexValid(int index)
{
	return (index >= 0 && index < count);
}

bool LinkedList::operator==(LinkedList& list1)
{
	if (list1.count != count)
	{
		return false;
	}
	while (head->next == nullptr)   
	{
		if (head->data != list1.head->data)
		{
			return false;
		}
		head = head->next;
		list1.head = list1.head->next;
	}
		return true;
}

LinkedList &LinkedList::operator=(LinkedList& list)
{
	clear();
	Node* temp = list.head;
	for (int i = 0; i < list.count; ++i)
	{
		push_back(temp->data);
		temp = temp->next;
	}
	return (*this);
}

void LinkedList::clear()
		{
			Node* temp = nullptr;
			while(head != nullptr) 
			{
				temp = head -> next;
				delete head;
				head = temp;	
			}
			head = nullptr;
			count = 0;
			return;
		}

void LinkedList::push_forward(int data)
		{
			//Node* newHead = new Node(data);
			//newHead->next = head;
			//head = newHead;
			head = new Node(data, head);
			if (tail == nullptr)
			{
				tail = head;
			}
			++count;
		}

void LinkedList::push_back(int data)
		{
			if (tail == nullptr)
			{
				return push_forward(data);
			}
			tail->next = new Node(data);
			tail = tail->next;
			++count;
		}

void LinkedList::insert(int data, int index)
		{
			if (index == count)
			{
				return push_back(data);
			}
			if (index == 0)
			{
				return push_forward(data);
			}
			if (indexValid(index))
			{
				Node* temp = head;
				for (int i = 0; i < index - 1; ++i)
				{
					temp = temp->next;
				}
				temp->next = new Node(data, temp->next);
				++count;
			}
		}

int LinkedList::extractHead()
		{
			if (count == 0)
			{
				return 0;
			}		
			Node* temp = head;
			head = head->next;
			int result = head->data; // ?
			delete temp;
			--count;
			if (count == 0)
			{
				tail = nullptr;
			}
			return result;
		}

int LinkedList::extractTail()
		{
			if (count == 0)
			{
				return 0;
			}
			if (count == 1)
			{
				return extractHead();
			}
			Node* temp = head;
			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}
			int result = temp->data; //?
			delete temp->next;
			temp->next = nullptr;
			--count;
			return result;
		}

int LinkedList::extractElement(int index)
		{
			if (!indexValid(index))
			{
				return 0;
			}
			if (index == 0)
			{
				return extractHead();
			}
			if (index == count - 1)
			{
				return extractTail();
			}

			Node* temp = head;
			for (int i = 0; i < index - 1; ++i)
			{
				temp = temp->next;
			}
			int result = temp->next->data;
			Node* todelete = temp->next;
			temp->next = temp->next->next;
			delete todelete;
			--count;
			return result;
		}

void LinkedList::extract_by_value(int value)
		{
			if (count <= 0)
			{
				return;
			}
			
			Node* temp = head;
			for (int i = 0; i < count; ++i)
			{
				if(temp->data == value)
				{
					extractElement(i);
					extract_by_value(value);
					
				}
				temp = temp->next;

			}

		}

void LinkedList::combine_list(LinkedList& list)
{
	 {
		Node* temp = list.head;
		for (int i = 0; i < list.count; ++i)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}
}