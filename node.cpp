#include <iostream>
using namespace std;

class Node
{
private:
	int data;
public:
	Node* left, *right;
	Node() : left(0), right(0), data(0) {};
	Node(int num) : left(0), right(0), data(num) {}
	Node(int num, Node* leftPtr, Node* rightPtr)
	{
		data = num;
		left = leftPtr;
		right = rightPtr;
	}

	void setData(int num)
	{
		data = num;
	}
	Node* insertNode(Node* ptr, Node* rptr)
	{
		if (!this)
		{
			return ptr;
		}
		else
		{
			if (ptr->getData() < rptr->getData())
			{
				left = left->insertNode(ptr, left);
			}
			else
			{
				right = right->insertNode(ptr, right);
			}
		}
		return this;
	}
	Node* removeNode(int num, Node*& rptr)
	{
		if (!rptr)
			return NULL;
		if (num == rptr->getData())
		{
			Node* ptr = rptr;
			{
				if (ptr->left)
				{
					rptr = rptr->left;
					while (rptr->right)
					{
						rptr = rptr->right;
					}
					rptr->right = ptr->right;
				}
				else if (ptr->right)
				{
					rptr = rptr->right;
					while (rptr->left)
					{
						rptr = rptr->left;
					}
					rptr->left = ptr->left;
				}
				else
				{
					if (left == ptr)
						left = NULL;
					if (right == ptr)
						right = NULL;
				}
				ptr->left = ptr->right = NULL;
				return ptr;
			}
		}
		if (num < rptr->getData())
			return rptr->removeNode(num, rptr->left);
		else if (num > rptr->getData())
			return rptr->removeNode(num, rptr->right);
	}

	int getData()
	{
		return data;
	}
	void display()
	{
		cout << data << endl;
	}

};
