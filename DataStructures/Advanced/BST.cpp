#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
	Node* left;
	Node* right;
	T value;
	int level;
	int height;
	int cnt;
	int subtree_size;

	Node (T x = 0, int _level = 0) {
		value = x;
		level = _level;
		height = 1;
		cnt = 0;
		subtree_size = 1;
		left = nullptr;
		right = nullptr;
	}

	void increaseCounter() { cnt++; }

	void updSubtreeSize() {
		int size = 1;
		if (this->left)
			size += this->left->subtree_size;
		if (this->right)
			size += this->right->subtree_size;
		this->subtree_size = size;
	}

	void updHeight() {
		if (this->left)
			height = max(height, this->left->height + 1);
		if (this->right)
			height = max(height, this->right->height + 1);
	}
};

template<typename T>
class BST {
public:
	Node<T>* root;
	int height;
	int size;

	BST() {
		root = nullptr;
		height = 0;
		size = 0;
	}

	Node<T>* insert(T x, Node<T>* node, int level = 1) {
		if (!node) {
			node = new Node<T>(x, level);
			size++;
			node->increaseCounter();
			height = max(height, level);
		} else {
			if (x < node->value)
				node->left = insert(x, node->left, level + 1);
			else if (x > node->value)
				node->right = insert(x, node->right, level + 1);
		}
		node->updHeight();
		node->updSubtreeSize();
		return node;
	}

	void insert(T value) { root = insert(value, root); }

	int getHeight() { return height; }

	int getSize() { return size; }

	Node<T>* getKth(int k, Node<T>* node) {
		int size_left = node->left ? node->left->subtree_size : 0;
		if (size_left == k - 1)
			return node;
		return k <= size_left ? getKth(k, node->left) : getKth(k - size_left - 1, node->right);
	}

	int getKth(int k) {
		Node<T>* node = getKth(k, root);
		return node->value;
	}

	bool isLeaf(T x, Node<T>* node) {
		if (node->value == x)
			return !node->left && !node->right;
		if (x < node->value)
			return node->left ? isLeaf(x, node->left) : false;
		else if (x > node->value)
			return node->right ? isLeaf(x, node->right) : false;
	}

	bool isLeaf(Node<T>* node) { return isLeaf(node->value, root); }

	bool isLeaf(T x) { return isLeaf(x, root); }

	bool isBalanced(Node<T>* node) {
		if (!node) return true;
		int height_left = node->left ? node->left->height : 0;
		int height_right = node->right ? node->right->height : 0;
		if (abs(height_left - height_right) > 1)
			return false;
		return isBalanced(node->left) && isBalanced(node->right);
	}

	bool isBalanced() { return isBalanced(root); }

	void printBranches(Node<T>* node) {  
    	if (node->left) printBranches(node->left);
    	if ((bool)node->left ^ (bool)node->right) cout << node->value << '\n';
    	if (node->right) printBranches(node->right);
	}

	void printLeaves(Node<T>* node) {
		if (node->left) printLeaves(node->left);
        if (!node->left && !node->right) cout << node->value << '\n';
        if (node->right) printLeaves(node->right);
	}

	void printJunctions(Node<T>* node) { 
		if (node->left) printJunctions(node->left);
		if (node->left && node->right) cout << node->value << '\n';
		if (node->right) printJunctions(node->right);
    }

	void inOrder(Node<T>* node) {
		if (node->left) inOrder(node->left);
		cout << node->value << '\n';
		if (node->right) inOrder(node->right);
	}

	void preOrder(Node<T>* node) {   
		cout << node->value << '\n';
		if (node->left) inOrder(node->left);
		if (node->right) inOrder(node->right);
	}

	void postOrder(Node<T>* node) {  
		if (node->left) inOrder(node->left);
		if (node->right) inOrder(node->right);
		cout << node->value << '\n';
	}

	void print(string mode) {
		for (int i = 0; i < (int)mode.size(); i++)
			mode[i] = tolower(mode[i]);
		if (mode == "branches")
			printBranches(root);
		else if (mode == "leaves")
			printLeaves(root);
		else if (mode == "junctions")
			printJunctions(root);
		else if (mode == "inorder" || mode == "asc")
			inOrder(root);
		else if (mode == "preorder")
			preOrder(root);
		else if (mode == "postorder")
			postOrder(root);
	}
};

int main()
{
	BST<int> tree;
	int T;
    while (T--) {
        int x;
        cin >> x;
        tree.insert(x);
    }
    cout << tree.getSize() << '\n';
    tree.print("ASC");
}
