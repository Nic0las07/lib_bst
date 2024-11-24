#include <iostream>

class node {
private:
	int data;
	node* left;
	node* right;
public:
	node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
	int getData() {
		return data;
	}
	node* getLeftChild() {
		return left;
	}
	node* getRightChild() {
		return right;
	}
	node* insertNode(int value);
	void inOrder();
};

node* node::insertNode(int num) {
	if (this == nullptr) {
		return new node(num);
	}
	if (this->data == num) {
		return this;
	}
	if (num > this->data) {
		this->right = this->right->insertNode(num);
	}
	else {
		this->left = this->left->insertNode(num);
	}
	return this;
}

void node::inOrder() {
	if (this == nullptr) {
		return;
	}
	this->left->inOrder();
	std::cout << this->data << ' ';
	this->right->inOrder();
}