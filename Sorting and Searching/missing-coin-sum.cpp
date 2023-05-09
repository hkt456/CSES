#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long coins[n];
    for(int i=0; i<n; i++) cin>>coins[i];
    long long ans=1;
    sort(coins, coins+n);
    for(int i=0; i<n; i++){
        if(ans<coins[i]){
            break;
            
        }
        else ans+=coins[i];
    }
    cout<<ans;
    return 0;
}