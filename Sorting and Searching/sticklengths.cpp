#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long arr[n],ans=0;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    long long median=arr[n/2];
    for(const long long i:arr){
        ans+=abs(median-i);
    }
    cout<<ans;
    return 0;
}