#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
int main(){
    long long n,x;
    cin>>n>>x;
    long long coins[n];
    for(long long i=0; i<n; i++) cin>>coins[i];
    long long dp[x+5];
    memset(dp, (long long) 0, sizeof(dp));
    dp[0]=1;
    for(long long i=1; i<=x; i++){
        for(long long j=0; j<n; j++){
            if(i-coins[j]>=0){
                dp[i]+=dp[i-coins[j]];
                dp[i]%=MOD;
            }
        }
    }
    // for(int i=0; i<=x; i++) cout<<dp[i]<<" ";
    cout<<dp[x];
}