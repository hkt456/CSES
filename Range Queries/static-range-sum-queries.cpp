#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,q,a,b;
    cin>>n>>q;
    long long arr[n+1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    for(int i=0; i<q; i++){
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<endl;
    }
    return 0;
}