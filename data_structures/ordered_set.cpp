#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, 
rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ordered_set<int> s;
    string c;
    while (cin >> c)
    {
        if (c == "insert") 
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (c == "find")
        {
            int x;
            cin >> x;
            cout << *s.find_by_order(x) << endl;
        }
        else if (c == "order")
        {
            int x;
            cin >> x;
            cout << s.order_of_key(x) << endl;
        }
    }
}
