#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data = 0,
         Node* left = nullptr, 
         Node* right = nullptr) : data(data), left(left), right(right) {};
    ~Node() {};
};

class Binary_tree
{
private: 
        Node* root;

        void print(ostream& stream, Node* node, int level = 0)
	    {
		    if (node == nullptr)
		    {
			    return;
		    }

		    print(stream, node->left, level + 1);

		    for (int i = 0; i < level; ++i)
		    {
			    stream << "  ";
		    }

		    stream << node->data << endl;

		    print(stream, node->right, level + 1);
	    }

        void printLinear(ostream& stream, Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		printLinear(stream, node->left);
		stream << node->data << " ";
		printLinear(stream, node->right);
	}

	    void insert(Node*& node, int element)
	    {
		    if (node == nullptr)
		    {
			    node = new Node(element);
		    }
		    else
		    {
			    if (node->data > element)
			    {
				    insert(node->left, element);
			    }
			    else if(node->data < element)
			    {
				insert(node->right, element);
			    }
		    }
	    }

     
        bool find(Node*& root, int element)
	    {
            if(root == nullptr)
            {
                return false;
            }
            else if(root->data == element)
            {
                return true;
            }
            else if(element <= root->data)
            {
                return find(root->left, element);
            }
            else
            {
                return find(root->right, element);
            }

	    }

        Node*& find_Max(Node*& root)
        {
            int temp = 0;
            int ltemp = 0;
            int rtemp = 0;
            temp = root->data;
            ltemp = find_Max(root->left)->data;
            rtemp = find_Max(root->right)->data;
            if(ltemp > temp)
            {
                temp = ltemp;
            }
            if(rtemp > temp)
            {
                temp = rtemp;
            }
            return root;
            

        }
	
        Node*& extract(Node*& node)
	    {
            if(root == nullptr)
            {
                return root;
            }
            else if(node->data < root->data)
            {
                root->left = extract(root->left);
            }
            else if(node->data > root->data)
            {
                root->right = extract(root->right);
            }
            else 
            {
                //case1:the node doesn't have child
                if(root->left == nullptr && root->right == nullptr)
                {
                    delete root;
                    root = nullptr;
                }
                //case2: the node has one child
                else if(root->left == nullptr)
                {
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->right == nullptr)
                {
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                // case 3: this node has 2 children
                else
                {
                    Node* temp = find_Max(root->left);
                    root->data = temp->data;
                    root->left = extract(root->left);

                }

            }
        }

public:
        void ADD(Node*& node, int element)
        {
            if(node == nullptr)
            {
                insert(node,element);
                cout << element << "ADDED" << endl;
            }
            else if (node->data == element)
            {
                cout << "CANNOT ADDED" << endl;
            }
            else
            {
                if (node->data > element)
			    {
				    insert(node, element);
			    }
			    else if(node->data < element)
			    {
				    insert(node, element);
			    }
                else if (node->data == element)
                {
                    cout << "CANNOT ADDED" << endl;
                }


            }
        }

        void Search(Node* root, int element)
        {
            if(find(root, element) == true)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }

        void Delete(Node* root)
        {
            if(extract(root))
            {
                cout << "DELETED" << endl;
            }
            else
            {
                cout << "Can't" << endl;
            }
        }

        Binary_tree() : root(nullptr) {}

	Binary_tree& operator+=(int element)
	{
		insert(root, element);
		return *this;
	}
	
	friend ostream& operator<<(ostream& stream, Binary_tree& tree);
    {
        stream << "_____START_____" << endl;
	    tree.printLinear(stream, tree.root);
	    stream << endl << "______END______" << endl;
	    return stream;
    }
};
