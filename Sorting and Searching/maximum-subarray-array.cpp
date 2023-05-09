#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0; i<n; i++) cin>>arr[i];
    long long currMax=arr[0], maxSum=arr[0];
    for(long long i=1; i<n; i++){
        currMax=max(currMax+arr[i], arr[i]);
        maxSum=max(currMax, maxSum);
    }
    cout<<maxSum;
    return 0;
}