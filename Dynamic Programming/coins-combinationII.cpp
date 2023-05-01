#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD= 1e9+7;
int main(){
    ll n,x;
    cin>>n>>x;
    ll coins[n];
    for(ll i=0; i<n; i++) cin>>coins[i]; 
    ll dp[x+5];
    memset(dp, (ll) 0, sizeof(dp));
    dp[0]=1;
    for(ll i=0; i<n; i++){
        for(ll j=1; j<=x; j++){
            if(j-coins[i]>=0){
                dp[j]+=dp[j-coins[i]];
                dp[j]%=MOD;
            }
        }
    }
    // for(int i=0; i<=x; i++) cout<<dp[i]<<" ";
    cout<<dp[x];
    return 0;
}