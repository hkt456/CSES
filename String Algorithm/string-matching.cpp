#include <bits/stdc++.h>
using namespace std;
 
string T, P, S;
int Z[2000005];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> T >> P;
    S = P + "$" + T;
 
    int n = (int)S.size();
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            Z[i] = min(Z[i - l], r - i + 1);
        while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
 
    int ans = 0;
    for (int i = P.size() + 1; i < S.size(); i++)
        if (Z[i] == P.size())
            ans++;
    
    cout << ans << '\n';
}