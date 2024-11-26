#include "BST.h"
#include <iostream>

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

void Node::insertR_ite(int k) {
	Node* current{ this };
	while (current != nullptr) {
		if (current->data == k) {
			current->weight += 1;
			break;
		}
		if (k > current->data) {
			if (current->right == nullptr) {
				current->right = new Node(k);
				break;
			}
			else {
				current = current->right;
			}
		}
		else {
			if (current->left == nullptr) {
				current->left = new Node(k);
				break;
			}
			else {
				current = current->left;
			}
		}
	}
}

bool Node::findValue(int k) {
	Node* current{ this };
	while (current != nullptr) {
		if (current->data == k) {
			return true;
		}
		if (k > current->data) {
			current = current->right;
		}
		else {
			current = current->left;

		}
	}
	return false;
}

Node* Node::findMin(Node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* Node::nodeEraser(int k) {
	Node* temp = nullptr;
	if (this == nullptr) {
		return this;
	}
	if (k == this->data) {
		if (this->right == nullptr && this->left == nullptr) {
			delete this;
			temp = nullptr;
			return temp;
		}
		if (this->right != nullptr && this->left == nullptr) {
			temp = this->right;
			delete this;
			temp = nullptr;
			return temp;
		}
		if (this->left != nullptr && this->right == nullptr) {
			temp = this->left;
			delete this;
			temp = nullptr;
			return nullptr;
		}
		if (this->left != nullptr && this->right != nullptr) {
			temp = findMin(this->right);
			this->data = temp->data;
			this->right = this->right->nodeEraser(temp->data);
			return this;
		}
	}
	if (k > this->data) {
		this->right = this->right->nodeEraser(k);
	}
	else {
		this->left = this->left->nodeEraser(k);
	}
	return this;
}

void Node::preOrder() {
	if (this == nullptr) {
		return;
	}
	std::cout << this->data << ' ';
	this->left->preOrder();
	this->right->preOrder();
}

void Node::inOrder() {
	if (this == nullptr) {
		return;
	}
	this->left->inOrder();
	std::cout << this->data << ' ';
	this->right->inOrder();
}

void Node::postOrder() {
	if (this == nullptr) {
		return;
	}
	this->left->postOrder();
	this->right->postOrder();
	std::cout << this->data << ' ';
}

int Node::BST_height() {
	int l{ 0 }, r{ 0 };
	if (this == nullptr) {
		return 0;
	}
	l = this->left->BST_height();
	r = this->right->BST_height();
	return std::max(l, r) + 1;
}

bool Node::isBst(int max, int min) {
	if (this == nullptr) {
		return true;
	}
	if (this->data > max || this->data < min) {
		return false;
	}
	return this->left->isBst(this->data, min) && this->right->isBst(max, this->data);
}
