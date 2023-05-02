#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int main(){
    ll N, Q, a, b;
    ll arr[maxN+5];
    cin>>N>>Q;
    for(ll i = 1; i <= N; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    for(ll q = 0; q < Q; q++){
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<endl;
    }

}