#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next, *prev;
	Node(int _val) {
		val = _val;
		next = nullptr;
		prev = nullptr;
	}
};

struct LinkedList
{
	public:
		Node *head, *tail;
		
		LinkedList() { head = tail = nullptr; }

		int cnt(int x) {
			int cnt = 0;
			auto cur = head;
			while (cur) {
				if (cur->val == x)
					cnt++;
				cur = cur->next;
			}
			return cnt;
		}

		int getNth(int n) {
			auto cur = head;
			while (n-- && cur)
				cur = cur->next;
			return cur ? cur->val : -1;
		}

		void insertLast(int x) {
			auto node = new Node(x);
			if (tail == nullptr) {
				head = node;
				tail = node;
				return;
			} else {
				tail->next = node;
				node->prev = tail;
				tail = node;
			}
		}

		void insertFirst(int x) {
			auto node = new Node(x);
			if (head == nullptr) {
				head = node;
				tail = node;
				return;
			} else {
				head->prev = node;
				node->next = head;
				head = node;
			}
		}

		void deleteFirst() {
			head = head->next;
			if (head != nullptr)
				head->prev = nullptr;
			else
				tail = nullptr;
		}

		void deleteLast() {
			tail = tail->prev;
			if (tail != nullptr)
				tail->next = nullptr;
			else
				head = nullptr;
		}

		void del(int x) {
			auto cur = head;
			while (cur && cur->val != x)
				cur=cur->next;
			if (!cur)
				return;
			if (cur == head)
				deleteFirst();
			else if (cur == tail) 
				deleteLast();
			else
			{
				cur->next->prev = cur->prev;
				cur->prev->next = cur->next;
			}
		}

		void print() {
			auto cur = head;
			while (cur) {
				if (cur != head)
					cout << ' ';
				cout << cur->val;
				cur = cur->next;
			}
			cout << '\n';
		}
};

int main()
{
	int n, x;
	auto ll = new LinkedList();
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "insertFirst") {
			cin >> x;
			ll->insertFirst(x);
		} else if (s == "delete") {
			cin >> x;
			ll->del(x);
		} else if (s == "deleteFirst")
			ll->deleteFirst();
		else if (s == "deleteLast")
			ll->deleteLast();
		else if (s == "insertLast") {
			cin >> x;
			ll->insertLast(x);
		} else if (s == "cnt") {
			cin >> x;
			cout << ll->cnt(x) << '\n';
		} else if (s == "getNth") {
			cin >> x;
			cout << ll->getNth(x) << '\n';
		}
	}
	ll->print();
}
