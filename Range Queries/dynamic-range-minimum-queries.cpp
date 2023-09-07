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

void update(int si, int ss, int se, int index, int val){
    if(index<ss||index>se) return;
    if(ss==se && ss==index){
        st[si]=val;
        return;
    }
    int mid = (ss + se) >> 1;
	update(2*si , ss , mid , index , val);
	update(2*si+1 , mid+1 , se , index , val);
	st[si] = min(st[2*si],st[2*si+1]);
}

int getMin(int si, int ss, int se, int l, int r){
    if(r<ss || l > se ) return INT_MAX;
    else if(ss>=l&&se<=r) return st[si];
    int mid=(se+ss)>>1;
    return min(getMin(2*si,ss,mid,l,r),getMin(2*si+1,mid+1,se,l,r));
}

int main(){
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int code; 
        cin>>code;
        if(code==1){
            int index, val;
            cin>>index>>val;
            update(1,1,n,index,val);
            arr[index]=val;
        }
        else{
            cin>>a>>b;
            cout<<getMin(1,1,n,a,b)<<endl;
        }
    }
    // cout<<getMin(1,1,n,5,6);

}