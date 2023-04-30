#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, num = 5, ans = 0;
    cin >> n;
    while (num <= n) {
        ans += n / num;
        num *= 5;
    }
    cout << ans << endl;
    return 0;
}