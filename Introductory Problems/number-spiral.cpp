#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long y,x;
        cin>>y>>x;
        if(y>x){
            if(y%2==0){
                long long num=y*y;
                cout<<num-x+1;
            }
            else{
                long long num=(y-1)*(y-1)+1;
                cout<<num+x-1;
            }
        }
        else{
            if(x%2==1){
                long long num=x*x;
                cout<<num-y+1;
            }
            else{
                long long num=(x-1)*(x-1)+1;
                cout<<num+y-1;
            }
        }
        cout<<endl;
    }
}