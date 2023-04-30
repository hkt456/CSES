#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=1;
    int temp=1;
    for(int i=0; i<s.length()-1; i++){
        if(s[i]==s[i+1]){
            temp++;
            while(s[i]==s[i+1]){
                temp++;
                i++;
                ans=max(ans, temp);
            }
        }
        temp=1;
    }
    if(ans==1) cout<<1;
    else cout<<ans-1;
    return 0;
}