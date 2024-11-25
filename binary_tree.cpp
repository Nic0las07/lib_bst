#include "binary_tree.h"

Node::Node(int value) {
	data = value;
	weight = 1;
	left = nullptr;
	right = nullptr;
}

int Node::getData() {
	return data;
}

Node* Node::getLeftChild() {
	return left;
}

Node* Node::getRightChild() {
	return right;
}

Node* Node::insertR(int k) {
	if (this == nullptr) {
		return new Node(k);
	}
	if (this->data == k) {
		this->weight += 1;
		return this;
	}
	if (k > this->data) {
		this->right = this->right->insertR(k);
	}
	else {
		this->left = this->left->insertR(k);
	}
	return this;
}

void Node::inOrder() {
	if (this == nullptr) {
		return;
	}
	this->left->inOrder();
	std::cout << this->data << ' ';
	this->right->inOrder();
}