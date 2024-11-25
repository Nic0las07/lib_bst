#include <iostream>

class Node {
private:
	int data;
	size_t weight;
	Node* left;
	Node* right;
public:
	Node(int value);
	int getData();
	Node* getLeftChild();
	Node* getRightChild();
	Node* insertR(int value);
	void inOrder();
};

