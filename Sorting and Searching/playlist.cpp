#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans=0;
    cin>>n;
    map<int,int> lastIndex;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];
    int i=1; 
    for(int j=1; j<=n; j++){
        i=max(i, lastIndex[arr[j]]+1);
        ans=max(ans, j-i+1);
        lastIndex[arr[j]]=j;
    }
    cout<<ans;
    return 0;
    
}