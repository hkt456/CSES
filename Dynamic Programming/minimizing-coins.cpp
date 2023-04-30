#include <bits/stdc++.h>
using namespace std;
#define maxN 1e6+5
#define maxC 1e6+5

int main(){
    int n, x;
    cin>>n>>x;
    long long coins[n], dp[x+5];
	for (int i = 0; i <= x+5; i++) { dp[i] = INT_MAX; }
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j-coins[i]>=0){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
    }
    cout<<(dp[x]==INT_MAX?-1:dp[x]);
}