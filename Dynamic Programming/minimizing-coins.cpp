#include <bits/stdc++.h>
using namespace std;
#define maxN 1e6+5
#define maxC 1e6+5

int main(){
    int n, x;
    cin>>n>>x;
    int coins[n], dp[x+5];
    memset(dp, maxC, sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=x; j++){
            if(j-coins[i]>=0){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
    }
    cout<<(dp[x]==maxN?-1:dp[x]);
}