#include <cmath>

struct node {
	int data;
	node* left;
	node* right;
	node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

node* node_creator_recursion(node* root, int num) {
	if (root == nullptr) {
		return new node(num);
	}
	if (root->data == num) {
		return root;
	}
	if (num > root->data) {
		root->right = node_creator_recursion(root->right, num);
	}
	else {
		root->left = node_creator_recursion(root->left, num);
	}
	return root;
}

node* node_creator_iteration(node* root, int num) {
	while (root != nullptr) {
		
		if (root->data == num) {
			break;
		}
		if (num > root->data) {
			if (root->right == nullptr) {
				root->right = new node(num);
				break;
			}
			root = root->right;
		}
		else {
			if (root->left == nullptr) {
				root->left = new node(num);
				break;
			}
			root = root->left;
		}
	}
	return root;
}

bool find_value(node* root, int num) {
	bool check{ false };
	while (root != nullptr) {
		if (root == nullptr) {
			check = false;
			break;
		}
		if (root->data == num) {
			check = true;
			break;
		}
		if (num > root->data) {
			root = root->right;
		}
		else {
			root = root->left;
		}
	}
	return check;
}

//INIZIO PARTE DI ELIMINAZIONE NODO

node* find_min(node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

node* node_eraser(node* root, int num) {
	node* temp = nullptr;
	if (root == nullptr) {
		return root;
	}
	if (num == root->data) {
		if (root->right == nullptr && root->left == nullptr) {
			delete root;
			root = nullptr;
			return root;
		}
		if (root->right != nullptr && root->left == nullptr) {
			temp = root->right;
			delete root;
			root = temp;
			return root;
		}
		if (root->left != nullptr && root->right == nullptr) {
			temp = root->left;
			delete root;
			root = temp;
			return root;
		}
		if (root->left != nullptr && root->right != nullptr) {
			temp = find_min(root->right);
			root->data = temp->data;
			root->right = node_eraser(root->right, temp->data);
			return root;
		}
	}
	if (num > root->data) {
		root->right = node_eraser(root->right, num);
	}
	else {
		root->left = node_eraser(root->left, num);
	}
	return root;
}

//FINE PARTE DI ELIMINAZIONE NODO

void preorder_traversal(node* root) {
	if (root == nullptr) {
		return;
	}
	std::cout << root->data << ' ';
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void inorder_traversal(node* root) {
	if (root == nullptr) {
		return;
	}
	inorder_traversal(root->left);
	std::cout << root->data << ' ';
	inorder_traversal(root->right);
}

void postorder_traversal(node* root) {
	if (root == nullptr) {
		return;
	}
	postorder_traversal(root->left);	
	postorder_traversal(root->right);
	std::cout << root->data << ' ';
}

int BST_height(node* root) {
	int l{ 0 }, r{ 0 };
	if (root == nullptr) {
		return 0;
	}
	l = BST_height(root->left);
	r = BST_height(root->right);
	return std::max(l,r) + 1;
}

bool is_bst(node* root, int max = INT_MAX, int min = INT_MIN) {
	if (root == nullptr) {
		return true;
	}
	if (root->data > max || root->data < min) {
		return false;
	}
	return is_bst(root->left, root->data, min) && is_bst(root->right, max, root->data);
}