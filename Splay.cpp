
//NOT NEEDED

/*/
	void SplayTree::Zig(Node* x) {
		Node* y = x->parent;
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

	void SplayTree::Zag(Node* x) {
		Node* y = x->parent;
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

	void SplayTree::Splay(Node* x) {
		if (!root || x == root || !x) {
			return;
		}
		while (true) {
			Node* parent = x->parent;
			if (!parent) {
				break;
			}
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
	
	SplayTree::SplayTree() {
			root = NULL;
		}

	bool SplayTree::Insert(int key) {
			Node* x = (Node*)malloc(sizeof(*x));	
			if (!x) {
				return false;
			}
			x->key = key;
			x->left = NULL;
			x->right = NULL;
			x->parent = NULL;
			if (!root) {
				root = x;
				return true;
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
			return true;
		}

	SplayTree::Node* SplayTree::Find(int key) {
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
			Splay(tempRoot);
			if (root == tempRoot) {
				return root;
			}
			return NULL;
		}

	bool SplayTree::Delete(int key) {
			Node* toDelete = Find(key);
			if (!toDelete) {
				return false;
			}
			if (!toDelete->left && !toDelete->right) {
				root = NULL;
				free(toDelete);
			}
			else if (!toDelete->left && toDelete->right) {
				root = toDelete->right;
				free(toDelete);
			}
			else if (toDelete->left && !toDelete->right) {
				root = toDelete->left;
				free(toDelete);
			} 
			else {
				Node* newRoot = toDelete->left;
				if (!newRoot->right) {
					newRoot->parent = NULL;
					newRoot->right = toDelete->right;
					toDelete->right->parent = newRoot;
					root = newRoot;
					free(toDelete);
					return true;
				}
				while (newRoot->right) {
					newRoot = newRoot->right;
				}
				newRoot->parent->right = NULL;
				newRoot->parent = NULL;
				newRoot->right = toDelete->right;
				toDelete->right->parent = newRoot;
				newRoot->left = toDelete->left;
				toDelete->left->parent = newRoot;
				root = newRoot;
				free(toDelete);
			}
			return true;
		}

	void SplayTree::Inorder(Node* root) {
			if (!root) return;
			Inorder(root->left);
			cout << root->key << "  ";
			Inorder(root->right);
		}*/
