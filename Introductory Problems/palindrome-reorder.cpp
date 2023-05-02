#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    map<char, string> m;
    cin>>s;
    for(char c:s){
        if(m.count(c)){
            m[c]+=c;
        }
        else{
            m[c]=c;
        }
    }
    string odd="",fir="", sec="";
    for(auto c:m){
        if(c.second.length()%2==1&&odd!=""){
            cout<<"NO SOLUTION";
            return 0;
        }
        else if(c.second.length()%2==1) {
            odd=c.second;
        }
        else{
            fir=c.second.substr(0, c.second.length()/2)+fir;
            sec+=c.second.substr(0, c.second.length()/2);
        }
    }
    cout<<fir+odd+sec;
    return 0;
}