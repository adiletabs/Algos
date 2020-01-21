#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	bool is_terminal;
	Node *son[26];

    Node() {
        is_terminal = false;
        for (int i = 0; i < 26; i++)
            son[i] = nullptr;
    }
};

class Trie {
private:
	bool is_empty(Node* node) 
    { 
        for (int i = 0; i < 26; i++) 
            if (node->son[i]) 
                return false; 
        return true; 
    }

public:
	Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string &word) 
	{
	    Node *cur = root;
        for (char c: word) {
            int ind = c - 'a';
            if (!cur->son[ind]) 
            	cur->son[ind] = new Node();
            cur = cur->son[ind];
        }
        cur->is_terminal = true;
    }

    bool search(string &word) {
        Node *cur = root;
        for (char c: word) {
            int ind = c - 'a';
            if (!cur->son[ind]) return false;
            cur = cur->son[ind];
        }
        return cur->is_terminal;
    }

    bool starts_with(string &prefix) {
        Node *cur = root;
        for (char c: prefix) {
            int ind = c - 'a';
            if (!cur->son[ind]) return false;
            cur = cur->son[ind];
        }
        return true;
    } 

    Node* remove(string &word, Node* node, int depth = 0) 
    { 
        if (!node) return nullptr; 
        if (depth == (int)word.size()) { 
            if (node->is_terminal) 
                node->is_terminal = false; 
            if (is_empty(node)) { 
                delete(node); 
                node = nullptr; 
            } 
            return node; 
        } 
        int ind = word[depth] - 'a'; 
        node->son[ind] = remove(word, node->son[ind], depth + 1); 
        if (is_empty(node) && !node->is_terminal) { 
            delete(node); 
            node = nullptr; 
        } 
        return node; 
    }
};

int main()
{
	Trie *trie = new Trie();
	int T;
	cin >> T;
	while (T--) {
		string command, s;
		cin >> command >> s;
		if (command == "insert") 
            trie->insert(s);
		else if (command == "find") {
			if (trie->search(s)) cout << "found\n";
			else cout << "not found\n";
		} else if (command == "remove") 
            trie->remove(s, trie->root);
	}
}
