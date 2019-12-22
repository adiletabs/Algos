#include <bits/stdc++.h>
using namespace std;

class Node 
{
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
    public:
   		Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string &s) 
	{
	    Node *cur = root;
	    for (int i = 0; i < (int)s.size(); i++) {
	    	int num = s[i] - 'a';
	        if (cur->son[num]) {
	            cur = cur->son[num];
	        }
	        else {
	            Node *node = new Node();
	            cur->son[num] = node; 
	            cur = node;
	        }
	    }
	    cur->is_terminal = true;
    }

    bool find_string(string s)
    {
    	Node *cur = root;
    	for (int i = 0; i < (int)s.size(); i++) {
    		int num = s[i] - 'a';
    		if (!(cur->son[num])) return false;
    		cur = cur->son[num];
    	}
    	return cur->is_terminal;
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
		if (command == "insert") trie->insert(s);
		else if (command == "find") {
			if (trie->find_string(s)) cout << "found!\n";
			else cout << "not found\n";
		}
	}
}
