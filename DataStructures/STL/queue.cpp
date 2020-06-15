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

struct Queue {
	private:
		Node *head = nullptr;
		Node *tail = nullptr;
		int cnt = 0;
	public:
		void push(int x) {
			Node *node = new Node(x);
			if (cnt == 0)
				head = node;
			else
				tail->prev = node;
			tail = node;
			cnt++;
		}

		int front() { return head->value; }

		void pop() {
			head = head->prev;
			cnt--;
		}

		void clear() {
			head = nullptr;
			tail = nullptr;
			cnt = 0;
		}

		int size() { return cnt; }

		bool empty() { return cnt == 0; }
};

int main() {
	Queue q;
	string s;
	while (true) {
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			q.push(n);
			cout << "ok\n";
		} else if (s == "pop") {
			cout << q.front() << '\n';
			q.pop();
		} else if (s == "front")
			cout << q.front() << '\n';
		else if (s == "size")
			cout << q.size() << '\n';
		else if (s == "clear") {
			q.clear();
			cout << "ok\n";
		} else {
			cout << "bye\n";
			break;
		}
	}
}
