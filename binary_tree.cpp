#include "BST.h"
#include <iostream>

Node::Node(int value) {
	data = value;
	weight = 1;
	lchild = nullptr;
	rchild = nullptr;
}

int Node::getData() {
	return data;
}

Node* Node::getLchild() {
	return lchild;
}

Node* Node::getRchild() {
	return rchild;
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
		this->rchild = this->rchild->insertR(k);
	}
	else {
		this->lchild = this->lchild->insertR(k);
	}
	return this;
}

Node* Node::insertI(int k) {
	Node* current{ this };
	while (current != nullptr) {
		if (current->data == k) {
			current->weight += 1;
			break;
		}
		if (k > current->data) {
			if (current->rchild == nullptr) {
				current->rchild = new Node(k);
				break;
			}
			else {
				current = current->rchild;
			}
		}
		else {
			if (current->lchild == nullptr) {
				current->lchild = new Node(k);
				break;
			}
			else {
				current = current->lchild;
			}
		}
	}
	return this;
}

bool Node::searchR(int k) {
	bool check{ true };
	if (this == nullptr) {
		return false;
	}
	if (this->data == k) {
		return true;
	}
	if (k > this->data) {
		check = this->rchild->searchR(k);
	}
	else {
		check = this->lchild->searchR(k);
	}
	return check;
}

bool Node::searchI(int k) {
	Node* current{ this };
	while (current != nullptr) {
		if (current->data == k) {
			return true;
		}
		if (k > current->data) {
			current = current->rchild;
		}
		else {
			current = current->lchild;

		}
	}
	return false;
}

Node* Node::findMin(Node* root) {
	while (root->lchild != nullptr) {
		root = root->lchild;
	}
	return root;
}

Node* Node::deleteNode(int k) {
	Node* temp = nullptr;
	if (this == nullptr) {
		return this;
	}
	if (k == this->data) {
		if (this->rchild == nullptr && this->lchild == nullptr) {
			delete this;
			temp = nullptr;
			return temp;
		}
		if (this->rchild != nullptr && this->lchild == nullptr) {
			temp = this->rchild;
			delete this;
			temp = nullptr;
			return temp;
		}
		if (this->lchild != nullptr && this->rchild == nullptr) {
			temp = this->lchild;
			delete this;
			temp = nullptr;
			return nullptr;
		}
		if (this->lchild != nullptr && this->rchild != nullptr) {
			temp = findMin(this->rchild);
			this->data = temp->data;
			this->rchild = this->rchild->deleteNode(temp->data);
			return this;
		}
	}
	if (k > this->data) {
		this->rchild = this->rchild->deleteNode(k);
	}
	else {
		this->lchild = this->lchild->deleteNode(k);
	}
	return this;
}

void Node::preOrder() {
	if (this == nullptr) {
		return;
	}
	std::cout << this->data << ' ';
	this->lchild->preOrder();
	this->rchild->preOrder();
}

void Node::inOrder() {
	if (this == nullptr) {
		return;
	}
	this->lchild->inOrder();
	std::cout << this->data << ' ';
	this->rchild->inOrder();
}

void Node::postOrder() {
	if (this == nullptr) {
		return;
	}
	this->lchild->postOrder();
	this->rchild->postOrder();
	std::cout << this->data << ' ';
}

int Node::BST_height() {
	int l{ 0 }, r{ 0 };
	if (this == nullptr) {
		return 0;
	}
	l = this->lchild->BST_height();
	r = this->rchild->BST_height();
	return std::max(l, r) + 1;
}

bool Node::isBst() {
	return isBstFunction(INT_MAX, INT_MIN);
}

bool Node::isBstFunction(int max, int min) {
	if (this == nullptr) {
		return true;
	}
	if (this->data > max || this->data < min) {
		return false;
	}
	return this->lchild->isBstFunction(this->data, min) && this->rchild->isBstFunction(max, this->data);
}

std::ostream& operator<<(std::ostream& os, Node& root) {
	os << "Nodo: " << root.data << ' ';
	if (root.lchild != nullptr) {
		os << "Figlio sinistro: " << root.lchild->data << ' ';
	}
	else {
		os << "Figlio sinistro: " << "Non c'è" << ' ';
	}
	if (root.rchild != nullptr) {
		os << "Figlio destro: " << root.rchild->data << ' ' << '\n';
	}
	else {
		os << "Figlio destro: " << "Non c'è" << ' ';
	}
	return os;
}

std::istream& operator>>(std::istream& is, Node*& root) {
	int value{ 0 };
	is >> value;
	root = new Node(value);
	return is;
}
