#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    vector<long long> lowerSum, upperSum;
    lowerSum.push_back(0);
    upperSum.push_back(0);
    long long midIndex = (long long)n/2; // 1. Proper casting
    for(int i=0; i<midIndex; i++){
        int sz = lowerSum.size();
        for(int j=0; j<sz; j++){
            lowerSum.push_back(lowerSum[j]+arr[i]);
        }
    }
    for(int i = midIndex; i<n; i++){
        int sz = upperSum.size();
        for(int j=0; j<sz; j++){
            upperSum.push_back(upperSum[j]+arr[i]); // 2. Fixed typo
        }
    }
    sort(upperSum.begin(), upperSum.end());
    sort(lowerSum.begin(), lowerSum.end());

    long long res = 0;
    for(int i=0; i<lowerSum.size(); i++){
        vector<long long>::iterator low = lower_bound(upperSum.begin(), upperSum.end(), x-lowerSum[i]);
        vector<long long>::iterator up = upper_bound(upperSum.begin(), upperSum.end(), x-lowerSum[i]);
        long long start = low - upperSum.begin();
        long long send = up - upperSum.begin();
        res+=send-start;
    }
    cout<<res;
}