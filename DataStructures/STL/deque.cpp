#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int value;
	Node *prev;
	Node(int x) {
		value = x;
		prev = nullptr;
	}
};

struct DEQUE
{
	private:
		Node *head = nullptr;
		Node *tail = nullptr;
		int cnt = 0;
	public:
		void push_back(int x) {
			Node *node = new Node(x);
			if (cnt == 0)
				head = node;
			else
				tail->prev = node;
			tail = node;
			cnt++;
		}

		void push_front(int x) {
			Node *node = new Node(x);
			if (cnt == 0)
				head = node;
			else
				head->prev = node;
			head = node;
			cnt++;
		}

		int back() { return tail->value; }

		int front() { return head->value; }

		void pop_back() {
			tail = tail->prev;
			cnt--;
		}

		void pop_front() {
			head = head->prev;
			cnt--;
		}

		void reverse() {
			Node * el = head;
			head = tail;
			tail = el;
		}

		bool empty() { return cnt == 0; }
};

int q;

int main()
{
	DEQUE dq;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (s == "push_back") {
			int n;
			cin >> n;
			dq.push_back(n);
		} else if (s == "push_front") {
			int n;
			cin >> n;
			dq.push_front(n);
		} else if (s == "front") {
			if (dq.empty()) cout << ";(";
			else cout << dq.front();
			cout << '\n';
		} else if (s == "back") {
			if (dq.empty()) cout << ";(";
			else cout << dq.back();
			cout << '\n';
		} else if (s == "reverse") dq.reverse();
	}
}
