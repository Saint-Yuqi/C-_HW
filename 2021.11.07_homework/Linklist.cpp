#include<iostream>

using namespace std;

struct Node 
{
	int data;
	Node* next;
	
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {};

	~Node() {};
};

class LinkedList 
{
private:
		Node* head;
		Node* tail;
		int count;

public:
		LinkedList() : head(nullptr), tail(nullptr), count(0) {}
		LinkedList(const LinkedList& list)
		{
			Node* temp = list.head;
			while (temp != nullptr)
			{
				push_back(temp->data);
				temp = temp->next;
			}
		}
		~LinkedList()
		{
			while (head != nullptr)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
		
		int& operator[](int index)
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

		bool indexValid(int index)
		{
			return (index >= 0 && index < count);
		}

		bool operator==(LinkedList& list1)
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

		LinkedList& operator=(LinkedList& list)
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

		void clear()
		{
			Node* temp = nullptr;
			while(head != nullptr) 
			{
				temp = head -> next;
				delete head;
				head = temp;	
			}
			head = nullptr;
			return;
		}

		void push_forward(int data)
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

		void push_back(int data)
		{
			if (tail == nullptr)
			{
				return push_forward(data);
			}
			tail->next = new Node(data);
			tail = tail->next;
			++count;
		}

		void insert(int data, int index)
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

		int extractHead()
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

		int extractTail()
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

		int extractElement(int index)
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

		void extract_by_value(int value)
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

		void combine_list(LinkedList& list)
		{
			Node* temp = list.head;
			for (int i = 0; i < list.count; ++i)
			{
				push_back(temp->data);
				temp = temp->next;
			}
		}

		friend ostream& operator<<(ostream& stream, const LinkedList& list)
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

int main(int argc, char* argv[])
{
	LinkedList list;
	LinkedList list1;
	cout << list << endl;
	list.push_back(1);
    list.push_back(2);
	list.push_back(3);
	list.push_back(3);


	cout << list << endl;
	list1.push_back(1);
    list1.push_back(4);


	cout << list1 << endl;
	if (list1 == list)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	
	cout << list << endl;
	cout << list1 << endl;
	list.combine_list(list1);

	cout<< list << endl;








	return EXIT_SUCCESS;
}