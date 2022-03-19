#include <iostream>

using namespace std;

class bst {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
	};
	Node* root;

	Node* helperinsert(int key, Node* node) {
		if(node == NULL) {
			node = new Node;
			node->data = key;
			node->left = NULL;
			node->right = NULL;
		} else if(key < node->data) {
			node->left = helperinsert(key, node->left);
		} else if(key > node->data) {
			node->right = helperinsert(key, node->right);
		}
		return node;
	}

public:
	bst() {
		root = NULL;
	}

	void insert(int key) {
		if(this->root == NULL) {
			this->root->data = key;
			this->root->left = NULL;
			this->root->right = NULL;
		} else {
			helperinsert(key, root);
		}
	}
};