#include <bits/stdc++.h>
using namespace std;

const int maxN = 2*1e5+5;
int n,q;
int arr[maxN];

struct Nodes{
    int val;
    int lazy;
    Nodes(): val(0), lazy(0){}
    Nodes(int val, int lazy): val(val), lazy(lazy){}
} st[4*maxN];


Nodes build(int si, int ss, int se){
    if(ss==se && ss==si) return st[ss] =  Nodes(arr[ss], 0);
    int mid = (ss+se)>>1;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    return st[si];
}

void down(int id){
    int t = st[id].lazy;
    st[2*id].lazy += t;
    st[2*id+1].lazy += t;
    st[2*id].val += t;
    st[2*id+1].val += t;
    st[id].lazy = 0;
}

void update(int si, int ss, int se, int l, int r, int val){
    if(ss>r || se<l) return;
    if(ss>=l && se<=r){
        st[si].val+=val;
        st[si].lazy+=val;
    }
    down(si);
    int mid = (ss+se)>>1;
    update(2*si, ss, mid, l, r, val);
    update(2*si+1, mid+1, se, l, r, val);
    arr[si] += val;
}

int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>arr[i];
    build(1, 1, n);
    while(q--){
        int code;
        int l,r;
        cin>>code;
        if(code==1){
            int val;
            cin>>l>>r>>val;
            update(1, 1, n, l, r, val);
        }
        else{
            int k;
            cin>>k;
            cout<<st[k].val<<endl;
        }
    }
    return 0;
}