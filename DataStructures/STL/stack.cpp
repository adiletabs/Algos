#include <bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node *prev;
	Node(int x) {
		value = x;
		prev = nullptr;
	}
};

struct Stack {
	private:
		Node *head = nullptr;
		int cnt = 0;
	public:
		void push(int x) {
			Node * node = new Node(x);
			node->prev = head;
			head = node;
			cnt++;
		}

		int back() { return head->value; }

		void pop() {
			if (cnt == 1)
				head = nullptr;
			else
				head = head->prev;
			cnt--;
		}

		void clear() {
			head = nullptr;
			cnt = 0;
		}

		int size() { return cnt; }

		bool empty() { return cnt == 0; }
};

int main() {
	Stack st;
	string s;
	while (true) {
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			st.push(n);
			cout << "ok\n";
		} else if (s == "pop") {
			cout << st.back() << '\n';
			st.pop();
		} else if (s == "back")
			cout << st.back() << '\n';
		else if (s == "size")
			cout << st.size() << '\n';
		else if (s == "clear") {
			st.clear();
			cout << "ok\n";
		} else {
			cout << "bye\n";
			break;
		}
	}
}
