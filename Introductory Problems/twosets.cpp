#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> a;
    if(n*(n+1)%4!=0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    long long fsum, ssum=0, num=1;
    fsum=(n*(n+1))/4;
    if(fsum%n==0){
        a.push_back(n);
        ssum+=n;
    }
    while(fsum!=ssum){
        if(fsum%n==0){
            a.push_back(n-num);
            a.push_back(num);
            ssum+=n;
        }
        else{
            a.push_back(n-num+1);
            a.push_back(num);
            ssum+=n+1;
        }
        num++;
    }
    sort(a.begin(), a.end());
    num=0;
    string s;
    cout<<a.size()<<"\n";
    for(long long i=1;i<=n;i++){
        if(num<a.size() && a[num]==i){
            cout<<i<<" ";
            num++;
        }
        else{
            s+=to_string(i) + " ";
        }
    }
    cout<<endl<<n-a.size()<<endl<<s;
    return 0;
}