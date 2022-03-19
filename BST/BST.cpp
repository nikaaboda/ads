#include <iostream>

using namespace std;

class BST {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node* parent;
	};
	Node* root;

	Node* helperinsert(int key, Node* node, Node* par) {

		if(node == NULL) {
			node = new Node;
			node->data = key;
			node->left = NULL;
			node->right = NULL;
			node->parent = par;
		} else if(key < node->data) {
			node->left = helperinsert(key, node->left, node);
		} else if(key > node->data) {
			node->right = helperinsert(key, node->right, node);
		}
		return node;
	}

	Node* helperSearch(int key, Node* node) {
		if(node == NULL) {
			return NULL;
		}
		if(key < node->data) {
			helperSearch(key, node->left);
		} else if(key > node->data) {
			helperSearch(key, node->right);
		} else {
			return node;
		}
	}

	Node* iterativeSearch(int key, Node* node) {
		if(node == NULL) {
			return NULL;
		}

		while(node != NULL && node->data != key) {
			if(key < node->data) {
				node = node->left;
			} else if(key > node->data) {
				node = node->right;
			} 
		}
		return node;
	}

	Node* helperFindMin(Node* node) {
		if(!node->left) {
			return node;
		} else {
			helperFindMin(node->left);
		}
	} 

	Node* helperFindMax(Node* node) {
		if(!node->right) {
			return node;
		} else {
			helperFindMax(node->right);
		}
	}

	void helperPrint(Node* node) {
		if(node != NULL) {
			helperPrint(node->left);
			cout << node->data << endl;
			helperPrint(node->right);
		}
	}

public:
	BST() {
		root = NULL;
	}

	void insert(int key) {
		if(this->root == NULL) {
			this->root = new Node;
			this->root->data = key;
			this->root->left = NULL;
			this->root->right = NULL;
		} else {
			helperinsert(key, root, NULL);
		}
	}

	Node* findMin() {
		Node* min = helperFindMin(this->root);
		return min;
	}

	Node* findMax() {
		Node* max = helperFindMax(this->root);
		return max;
	}

	Node* search(int key) {
		Node* result = helperSearch(key, this->root);
		return result;
	}

	Node* successor(Node* node) {
		if(node->right != NULL) {
			return helperFindMin(node->right);
		}

		Node* par = node->parent;
		while(node == par->right && par != NULL) {
			 node = par;
			 par = par->parent;
		}
		return par;
	}

	Node* predecessor(Node* node) {
		if(node->left != NULL) {
			return helperFindMax(node->left);
		}

		Node* par = node->parent;
		while(par != NULL && node == par->left) {
			node = par;
			par = par->parent;
		}

		return par;
	}

	void transplant(Node* replaced, Node* replacement) {
		if(replaced == root) {
			root = replacement;
		} else if(replaced == replaced->parent->left) {
			replacement = replaced->parent->left;
		} else {
			replacement = replaced->parent->right;
		}

		replacement->parent = replaced->parent;
	}

	void deleteNode(Node* toBeDeleted) {
		if(toBeDeleted->left == NULL) {
			transplant(toBeDeleted, toBeDeleted->right);
		} else if(toBeDeleted->right == NULL) {
			transplant(toBeDeleted, toBeDeleted->left);
		} else {
			Node* replacement = helperFindMin(toBeDeleted->right);
			if(replacement->parent != toBeDeleted) {
				transplant(replacement, replacement->right);
				replacement->right = toBeDeleted->right;
				toBeDeleted->right->parent = replacement;	
			}
			transplant(toBeDeleted, replacement);
			replacement->left = toBeDeleted->left;
			toBeDeleted->left->parent = replacement;
		}
	}

	void print() {
		helperPrint(this->root);
	}

};


int main() {
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(20);
	tree.print();
	tree.deleteNode(tree.search(15));
	tree.print();
	return 0;
}