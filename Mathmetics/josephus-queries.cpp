#include <bits/stdc++.h>
using namespace std;


int solve(int n, int k){
    if(n==1) return 1;
    if(k<=(n+1)/2) 
    {
        if(2*k>n) return (2*k)%n;
        else return 2*k;
    }
    int temp=solve(n/2,k-(n+1)/2);
    if(n%2==1) return 2*temp+1;
    return 2*temp-1;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}