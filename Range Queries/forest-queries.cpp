#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int getAns(int sx , int sy , int ex , int ey)
{
	return arr[ex][ey] - arr[sx-1][ey] - arr[ex][sy-1] + arr[sx-1][sy-1];
}

int main(){
    int n,q;
    cin>>n>>q;
    int a,b,c,d;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char ch;
            cin>>ch;
            arr[i][j]= ch=='*';
            arr[i][j]+=arr[i][j-1];
        }
    }    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j]+=arr[i-1][j];
        }
    }
    while(q--){
        cin>>a>>b>>c>>d;
        cout<<getAns(a,b,c,d)<<endl;
    }
}