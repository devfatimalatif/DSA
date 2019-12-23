#pragma once
#include "Node.cpp"

class Tree
{
private:
	Node* root;
	int count;

public:
	Tree() :root(0), count(0) {}
	Tree(Node* ptr)

	{
		root = ptr;
		root->left = 0;
		root->right = 0;
		count = 1;
	}


	void insertData(int num)
	{
		Node* ptr = new Node(num);
		insert(ptr);
	}
	void insert(Node*& ptr)
	{
		if (!root)
		{
			root = ptr;
		}
		else
			root->insertNode(ptr, root);
		count++;
		//cout << count << endl;
		ptr->left = 0;
		ptr->right = 0;
		ptr = NULL;
	}

	Node* removeRoot()
	{
		Node* ptr = root;
		if (count == 1)
			root = NULL;
		else if (ptr->left)
		{
			root = root->left;
			while (root->right)
			{
				root = root->right;
			}
			root->right = ptr->right;
		}
		else
		{
			root = root->right;
			while (root->left)
			{
				root = root->left;
			}
			root->left = ptr->left;
		}
		ptr->left = ptr->right = NULL;
		--count;
		return ptr;
	}
	Node* remove(int num)
	{
		if (isEmpty())
		{
			cout << "Not Found\n";
			return NULL;
		}
		else if (num == root->getData())
		{
			return removeRoot();
		}
		else
		{
			Node* newNode;
			if (num < root->getData())
			{
				newNode = root->removeNode(num, root->left);
				if (newNode)
					--count;
				return newNode;
			}
			else
			{
				newNode = root->removeNode(num, root->right);
				if (newNode)
					--count;
				return newNode;
			}
		}
	}
	int getCount()
	{
		return count;
	}
	int getRoot()
	{
		return root->getData();
	}
	int getMin()
	{
		if (isEmpty())
		{
			cout << "Empty\n";
			return -1;
		}
		Node* ptr = root;
		while (ptr->left)
			ptr = ptr->left;
		return ptr->getData();
	}
	int getMax()
	{
		if (isEmpty())
		{
			cout << "Empty\n";
			return -1;
		}
		Node* ptr = root;
		ptr = ptr->right;
		while (ptr->right)
			ptr = ptr->right;
		return ptr->getData();
	}
	bool search(int num)
	{
		Node* ptr;
		ptr = root;
		while (ptr)
		{
			if (ptr->getData() < num)
				ptr = ptr->right;
			else if (ptr->getData() > num)
				ptr = ptr->left;
			else if (ptr->getData() == num)
				return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (root)
			return false;
		else
			return true;
	}
	bool isNotEmpty()
	{
		if (!root)
			return false;
		else
			return true;
	}

	void inorder(Node *&ptr)
	{

		if (ptr == NULL)
			return;
		inorder(ptr->right);
		ptr->display();
		inorder(ptr->left);
	}
	void preorder(Node *&ptr)
	{
		if (ptr == NULL)
			return;
		ptr->display();
		preorder(ptr->right);
		preorder(ptr->left);
	}
	void postorder(Node *&ptr)
	{
		if (ptr == NULL)
			return;
		inorder(ptr->right);
		inorder(ptr->left);
		ptr->display();
	}

	void displayNodes(Node* ptr)
	{
		if (ptr)
		{
			ptr->display();
			if (ptr->left)
				displayNodes(ptr->left);
			if (ptr->right)
				displayNodes(ptr->right);
		}
		else
			cout << "No Node\n";
	}
	void display()
	{
		Node* ptr;
		ptr = root;
		cout << "\nNodes are:\n";
		displayNodes(ptr);
	}
};
























