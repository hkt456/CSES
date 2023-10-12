
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e6+6;
int dp[mxN][3];

const int md = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i < mxN; i++) {
        dp[i][1] = (dp[i-1][1]*4%md + dp[i-1][2])%md;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2%md)%md;
    }
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout<<(dp[n][1] + dp[n][2])%md<<endl;
    }

}