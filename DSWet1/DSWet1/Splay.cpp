#ifndef _SPLAY_
#define _SPLAY_
template <class T>
class Node {
	public:
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
		T data;
		Node<T>(const T& data) : data(data) {
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
};
template <class T>
class SplayTree {	
	Node<T>* root;
	void Zig(Node<T>* x) {
		Node<T>* y = x->parent;
		y->left = x->right;
		x->right = y;
		x->parent = y->parent;
		if (x->parent) {
			if (x->parent->left == y) {
				x->parent->left = x;
			}
			else {
				x->parent->right = x;
			}
		}
		y->parent = x;
	}
	void Zag(Node<T>* x) {
		Node<T>* y = x->parent;
		y->right = x->left;
		x->left = y;
		x->parent = y->parent;
		if (x->parent) {
			if (x->parent->left == y) {
				x->parent->left = x;
			}
			else {
				x->parent->right = x;
			}
		}
		y->parent = x;
	}
	void Splay(Node<T>* x) {
		if (!root || x == root || !x) {
			return;
		}
		while (true) {
			Node<T>* parent = x->parent;
			if (!parent) {
				break;
			}
			Node<T>* grandParent = parent->parent;
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
	public:
		SplayTree<T>() {
			root = nullptr;
		}
		Node<T>* GetRoot() {
			return this->root;
		}
		bool Insert(const T& newData) {
			Node<T>* x = new Node<T>(newData);
			if (!x) {
				return false;
			}

			if (!root) {
				root = x;
				return true;
			}
			Node<T>* tempRoot = root;
			while (true)
			{
				if (x->data < tempRoot->data) {
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
			return true;
		}
		Node<T>* Find(const T& toFind) {
			Node<T>* tempRoot = root;
			while (tempRoot) {
				if (toFind == tempRoot->data) {
					break;
				}
				else if (toFind < tempRoot->data) {
					tempRoot = tempRoot->left;
				}
				else {
					tempRoot = tempRoot->right;
				}
			}
			Splay(tempRoot);
			if (root == tempRoot) {
				return root;
			}
			return nullptr;
		}
		bool Delete(const T& toFind) {
			Node<T>* toDelete = Find(toFind);
			if (!toDelete) {
				return false;
			}
			if (!toDelete->left && !toDelete->right) {
				root = nullptr;
				delete(toDelete);
			}
			else if (!toDelete->left && toDelete->right) {
				root = toDelete->right;
				delete(toDelete);
			}
			else if (toDelete->left && !toDelete->right) {
				root = toDelete->left;
				delete(toDelete);
			}
			else {
				Node<T>* newRoot = toDelete->left;
				if (!newRoot->right) {
					newRoot->parent = nullptr;
					newRoot->right = toDelete->right;
					toDelete->right->parent = newRoot;
					root = newRoot;
					delete(toDelete);
					return true;
				}
				while (newRoot->right) {
					newRoot = newRoot->right;
				}
				newRoot->parent->right = nullptr;
				newRoot->parent = nullptr;
				newRoot->right = toDelete->right;
				toDelete->right->parent = newRoot;
				newRoot->left = toDelete->left;
				toDelete->left->parent = newRoot;
				root = newRoot;
				delete(toDelete);
			}
			return true;
		}
		void Inorder(Node<T>* root) {
			if (!root) return;
			Inorder(root->left);
			cout << root->data << "  ";
			Inorder(root->right);
		}
};

#endif

