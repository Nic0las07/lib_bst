#ifndef BST_H
#define BST_H
#include <climits>

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
	Node* insertI(int k);
	void insertR(int k);
	bool searchI(int k);
	bool searchR(int k);
	Node* findMin(Node* root);
	Node* deleteNode(int k);
	void preOrder();
	void inOrder();
	void postOrder();
	int BST_height();
	bool isBst(int max = INT_MAX, int min = INT_MIN);
};

#endif