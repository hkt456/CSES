#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    int p_begin = 0, p_end = n - 1;
    vector<long long> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    while (p_begin < p_end) {
        if (weights[p_begin] + weights[p_end] <= x) {
            n--, p_begin++, p_end--;
        } else {
            p_end--;
        }
    }
    cout << n << endl;
}