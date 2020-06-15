#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

template<typename T>
class HEAP {
	private:
		int size;
		T h[N];

	public:
		void siftUp(int pos) {
			int npos = pos >> 1;
			while (npos && h[pos] > h[npos]) {
				swap(h[pos], h[npos]);
				pos = npos;
				npos = pos >> 1;
			}
		}

		void siftDown(int pos, T a[], int sz) {
			while (pos <= sz) {
				int l = pos + pos;
				int r = l + 1;
				if (l > sz) break;
				else if (r > sz) {
					if (a[l] > a[pos])
						swap(a[l], a[pos]);
					break;
				}

				if (a[l] <= a[pos] && a[r] <= a[pos]) break;
				if (a[l] > a[pos] && a[r] > a[pos]) {
					if (a[r] > a[l]) {
						swap(a[pos], a[r]);
						pos = r;
					} else {
						swap(a[pos], a[l]);
						pos = l;
					}
				} else if (a[l] > a[pos]) {
					swap(a[pos], a[l]);
					pos = l;
				} else if (a[r] > a[pos]) {
					swap(a[pos], a[r]);
					pos = r;
				}
			}
		}

		void siftDown(int pos) { siftDown(pos, h, size); }

		void insert(T x) {
			h[++size] = x;
			siftUp(size);
		}

		void build(T a[], int n) {
			for (int i = 0; i < n; i++)
				insert(a[i]);
		}

		T getMax() { return h[1]; }

		int getSize() { return size; }

		void heapSort(T a[], int n) {
			build(a, n);
			T help[n + 1];
			int sz = n;
			for (int i = 1; i <= n; i++)
				help[i] = h[i];
			for (int i = 0; i < n - 1; i++) {
				swap(help[1], help[n - i]);
				siftDown(1, help, --sz);
			}
			for (int i = 0; i < n; i++)
				a[i] = help[i + 1];
		}

		void delMax() {
			h[1] = h[size--];
			siftDown(1);
		}

		void increasePriority(int pos, T x) {
			if (pos > size) cout << "error\n";
			else {
				h[pos] = x;
				siftUp(pos);
			}
		}

		void decreasePriority(int pos, T x) {
			if (pos > size) cout << "error\n";
			else {
				h[pos] = x;
				siftDown(pos);
			}
		}

		void print() {
			for (int i = 1; i <= size; i++)
				cout << h[i] << ' ';
			cout << '\n';
		}
};

int a[N];

int main() {
	int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    HEAP<int> heap;
    heap.heapSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
