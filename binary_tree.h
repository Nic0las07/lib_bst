#include <iostream>

class node {
private:
	int data;
	size_t weight;
	node* left;
	node* right;
public:
	node(int value) {
		data = value;
		wight = 1;
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
		this->weight += 1;
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