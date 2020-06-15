#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, 
rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_set<int> s;
    string c;
    int x;
    while (cin >> c >> x) {
        if (c == "insert") 
            s.insert(x);
        else if (c == "find") 
            cout << *s.find_by_order(x) << '\n';
        else if (c == "order") 
            cout << s.order_of_key(x) << '\n';
        else if (c == "lb")
            cout << *s.lower_bound(x) << '\n';
        else if (c == "ub")
            cout << *s.upper_bound(x) << '\n';
        else if (c == "erase")
            s.erase(x);
    }
}
