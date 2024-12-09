#ifndef BST_H
#define BST_H
#include <climits>
#include <iostream>

class Node {
private:
	int data;
	size_t weight;
	Node* lchild;
	Node* rchild;
public:
	Node(int value = 0);
	int& getData();
	Node* getLchild();
	Node* getRchild();
	Node* insertR(int k);
	Node* insertI(int k);
	bool searchI(int k);
	bool searchR(int k);
	Node* findMin(Node* root);
	Node* deleteNode(int k);
	void preOrder();
	void inOrder();
	void postOrder();
	int BST_height();
	bool isBst(int max = INT_MAX, int min = INT_MIN);
	friend std::ostream& operator<<(std::ostream& os, Node& root);
	friend std::istream& operator>>(std::istream& is, Node*& root);
};

#endif
