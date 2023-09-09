#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
int arr[N];
int st[4*N];

int build(int si, int ss, int se){
    if(ss==se) return st[si]=arr[ss];
    int mid=(ss+se)>>1;
    
}

int main(){
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>arr[i];
    build(1,1,n);
}