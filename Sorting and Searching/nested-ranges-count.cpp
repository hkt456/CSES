#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> ranges;
    indexed_set<int> x;
    indexed_set<int> y;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ranges.push_back({a, b, i});
        x.insert(b);
        y.insert(b);
    }
    sort(ranges.begin(), ranges.end(), [](auto a, auto b) {
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        if (a1 != b1) return a1 < b1;
        else return a2 > b2;
    });
 
    vector<int> ans(n);
    for (auto [a, b, i] : ranges) {
        y.erase(y.find_by_order(y.order_of_key(b)));
        ans[i] = y.order_of_key(b + 1);
    }
 
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
 
    sort(ranges.begin(), ranges.end(), [](auto a, auto b) {
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        if (a1 != b1) return a1 > b1;
        else return a2 < b2;
    });
 
    vector<int> ans2(n);
    for (auto [a, b, i] : ranges) {
        x.erase(x.find_by_order(x.order_of_key(b)));
        ans2[i] = x.size() - x.order_of_key(b);
    }
 
    for (int i = 0; i < n; i++)
        cout << ans2[i] << " ";
    cout << endl;
    return 0;
}