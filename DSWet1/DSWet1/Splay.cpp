#include <stdlib.h>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	Node* parent;
	int key;
};

class SplayTree {
	Node* root;

	void Zig(Node* x) {
		Node* y = x->parent;
		y->left = x->right;
		x->right = y;
		x->parent = y->parent;
		y->parent = x;
	}

	void Zag(Node* x) {
		Node* y = x->parent;
		y->right = x->left;
		x->left = y;
		x->parent = y->parent;
		y->parent = x;
	}

	void Splay(Node* x) {
		if (!root || x == root || !x) {
			return;
		}
		while (true) {
			Node* parent = x->parent;
			Node* grandParent = parent->parent;
			if (!grandParent) {
				//Zig
				if (parent->left == x) {
					Zig(x);
				}
				//Zag
				else {
					Zag(x);
				}
				break;
			}
			else if (grandParent->left == parent) {
				//ZigZig
				if (parent->left == x) {
					Zig(parent);
					Zig(x);
				}
				//ZagZig
				else {
					Zag(x);
					Zig(x);
				}
			}
			else {
				if (parent->left == x) {
					//ZigZag
					Zig(x);
					Zag(x);
				}
				else {
					//ZagZag
					Zag(parent);
					Zag(x);
				}
			}
		}
		root = x;
	}

	Node* RegFind(int key) {
		Node* tempRoot = root;
		while (tempRoot) {
			if (key == tempRoot->key) {
				break;
			}
			else if (key < tempRoot->key) {
				tempRoot = tempRoot->left;
			}
			else {
				tempRoot = tempRoot->right;
			}
		}
		return tempRoot;
	}

	public:
		SplayTree() {
			root = NULL;
		}

		void Insert(Node* x) {
			if (!x) {
				return;
			}
			if (!root) {
				root = x;
				return;
			}
			Node* tempRoot = root;
			while (true)
			{
				if (x->key < tempRoot->key) {
					if (!tempRoot->left) {
						tempRoot->left = x;
						x->parent = tempRoot;
						break;
					}
					else {
						tempRoot = tempRoot->left;
					}
				} 
				else {
					if (!tempRoot->right) {
						tempRoot->right = x;
						x->parent = tempRoot;
						break;
					}
					else {
						tempRoot = tempRoot->right;
					}
				}

			}
			Splay(x);
		}

		Node* Find(int key) {
			Node* tempRoot = RegFind(key);
			Splay(tempRoot);
			if (root == tempRoot) {
				return root;
			}
			return NULL;
		}

		bool Delete(int key) {
			Node* toDelete = Find(key);
			if (!toDelete) {
				return false;
			}
			if (!toDelete->left && !toDelete->right) {
				root = NULL;
				free(toDelete);
				return true;
			}
			else if (!toDelete->left && toDelete->right) {
				root = toDelete->right;
			}
		}
};
