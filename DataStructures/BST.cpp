#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node
{
	public:
		Node* left;
		Node* right;
		T value;
		int level;
		int height;
		int cnt;
		int subtree_size;

		Node (T x = 0, int _level = 0) 
		{
			value = x;
			level = _level;
			height = 1;
			cnt = 0;
			subtree_size = 1;
			left = nullptr;
			right = nullptr;
		}

		void increaseCounter() { cnt++; }

		void updSubtreeSize() 
		{
			int size = 1;
			if (this->left != nullptr)
				size += this->left->subtree_size;
			if (this->right != nullptr)
				size += this->right->subtree_size;
			this->subtree_size = size;
		}

		void updHeight() 
		{
			if (this->left != nullptr)
				height = max(height, this->left->height + 1);
			if (this->right != nullptr)
				height = max(height, this->right->height + 1);
		}
};

template<typename T>
class BST
{
	public:
		Node<T>* root;
		int height;
		int size;

		BST() 
		{
			root = nullptr;
			height = 0;
			size = 0;
		}

		Node<T>* insert(T x, Node<T>* t, int level = 1) 
		{
			if (t == nullptr) {
				t = new Node<T>(x, level);
				size++;
				t->increaseCounter();
				height = max(height, level);
			}
			else {
				if (x < t->value)
					t->left = insert(x, t->left, level + 1);
				else if (x > t->value)
					t->right = insert(x, t->right, level + 1);
			}
			t->updHeight();
			t->updSubtreeSize();
			return t;
		}

		void insert(T value) { root = insert(value, root); }

		int getHeight() { return height; }

		int getSize() { return size; }

		Node<T>* getKth(int k, Node<T>* t) 
		{
			int size_left = t->left == nullptr ? 0 : t->left->subtree_size;
			if (size_left == k - 1)
				return t;
			return k <= size_left ? getKth(k, t->left) : getKth(k - size_left - 1, t->right);
		}

		int getKth(int k) 
		{
			Node<T>* t = getKth(k, root);
			return t->value;
		}

		bool isLeaf(T x, Node<T>* t) 
		{
			if (t->value == x)
				return t->left == nullptr && t->right == nullptr;
			if (x < t->value)
				return t->left == nullptr ? false : isLeaf(x, t->left);
			else if (x > t->value)
				return t->right == nullptr ? false : isLeaf(x, t->right);
		}

		bool isLeaf(Node<T>* t) { return isLeaf(t->value, root); }

		bool isLeaf(T x) { return isLeaf(x, root); }

		bool isBalanced(Node<T>* t) 
		{
			if (t == nullptr)
				return true;
			int height_left = t->left == nullptr ? 0 : t->left->height;
			int height_right = t->right == nullptr ? 0 : t->right->height;
			if (abs(height_left - height_right) > 1)
				return false;
			return isBalanced(t->left) && isBalanced(t->right);
		}

		bool isBalanced() { return isBalanced(root); }

		void printBranches(Node<T>* t) 
		{  
	        if (t->left != nullptr) printBranches(t->left);
	        if ((t->left != nullptr) ^ (t->right != nullptr)) cout << t->value << endl;
	        if (t->right != nullptr) printBranches(t->right);
	    }

		void printLeaves(Node<T>* t) 
		{
			if (t->left != nullptr) printLeaves(t->left);
	        if (t->left == nullptr && t->right == nullptr) cout << t->value << endl;
	        if (t->right != nullptr) printLeaves(t->right);
		}

		void printJunctions(Node<T>* t) 
		{ 
	        if (t->left != nullptr) printJunctions(t->left);
	        if (t->left != nullptr && t->right != nullptr) cout << t->value << endl;
	        if (t->right != nullptr) printJunctions(t->right);
	    }

		void inOrder(Node<T>* t) 
		{
			if (t->left != nullptr) inOrder(t->left);
			cout << t->value << endl;
			if (t->right != nullptr) inOrder(t->right);
		}

		void preOrder(Node<T>* t) 
		{   
			cout << t->value << endl;
			if (t->left != nullptr) inOrder(t->left);
			if (t->right != nullptr) inOrder(t->right);
		}

		void postOrder(Node<T>* t) 
		{  
			if (t->left != nullptr) inOrder(t->left);
			if (t->right != nullptr) inOrder(t->right);
			cout << t->value << endl;
		}

		void print(string mode) 
		{
			for (int i = 0; i < mode.size(); i++)
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
	int x;
    while (cin >> x) 
    {
        if (x == 0) break;
        tree.insert(x);
    }
    cout << tree.getSize() << '\n';
    print("ASC");
}
