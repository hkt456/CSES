#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int num=1;
    for(int i=0; i<n-1; i++){
        if(arr[i]!=arr[i+1]) num++;
    }
    cout<<num;
    return 0;
}