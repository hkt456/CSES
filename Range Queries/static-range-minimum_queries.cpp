#include <bits/stdc++.h>
using namespace std;
 
const int N = 200001;
int arr[N];
int st[4*N];
 
int build(int si, int ss, int se){
    if(ss==se) return st[si]=arr[se];
    int mid = (se+ss)>>1;
    return st[si]=min(build(2*si, ss, mid), build(2*si+1, mid+1, se));
}
int getMin(int si, int ss, int se, int l, int r){
    if(l>se || r<ss) return INT_MAX;
    if(ss>=l && se <=r) return st[si];
    int mid=(se+ss)>>1;
    return min(getMin(2*si, ss, mid, l, r), getMin(2*si+1, mid+1, se, l, r));
}
 
int main(){
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        cin>>a>>b;
        cout<<getMin(1,1,n,a,b)<<endl;
    }
}