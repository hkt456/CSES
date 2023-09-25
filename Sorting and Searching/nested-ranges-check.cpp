#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<tuple<int,int,int>> ranges;
    multiset<int> x;
    multiset<int> y;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ranges.push_back({a, b, i});
        x.insert(b);
        y.insert(b);
    }
    sort(ranges.begin(), ranges.end(), [](auto a, auto b){
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        if (a1 != b1) return a1 < b1;
        else return a2 > b2;
    });
    vector<int> ans(n);
    for (auto [a, b, i] : ranges) {
        if (y.find(b) != y.end()) {
            y.erase(y.find(b));
            ans[i] = (y.upper_bound(b) != y.begin());
        }
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
        if (x.find(b) != x.end()) {
            x.erase(x.find(b));
            ans2[i] = (x.lower_bound(b) != x.end());
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans2[i] << " ";
    cout << endl;
    return 0;
}
