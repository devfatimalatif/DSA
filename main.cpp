// Binary_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.cpp"

using namespace std;

int main()
{
	Tree myTree;
	Node* n1, *n2, *n3, *n4, *n5, *n6;
	n1 = new Node(55);
	n2 = new Node(54);
	n3 = new Node(522);
	n4 = new Node(65);
	n5 = new Node(11);
	n6 = new Node(90);

	myTree.insert(n1);
	myTree.insert(n2);
	myTree.insert(n3);
	myTree.insert(n4);
	myTree.insert(n5);
	myTree.insert(n6);

	if (myTree.search(522))
		cout << 522 << " Found\n";
	else
		cout << 522 << " Not Found\n";

	if (myTree.search(34))
		cout << 34 << " Found\n";
	else
		cout << 34 << " Not Found\n";
	//cout << "Root is: ";
	//cout << myTree.getRoot() << endl;
	cout << "Nodes: ";
	cout << myTree.getCount() << endl;
	myTree.remove(54);
	cout << "Hence the node is deletsd!";
	cout << "The roots are:";
	myTree.display();
	cout << "Root is: ";
	cout << myTree.getRoot() << endl;
	cout << "The Value of max Node is:";
	cout << myTree.getMax() << endl;
	system("Pause");
		return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
