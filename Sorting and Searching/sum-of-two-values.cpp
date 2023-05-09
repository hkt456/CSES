#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie()->sync_with_stdio(0);
    long long n,x;
    cin>>n>>x;
    vector<pair<long long,int>> values;
    for(int i=0; i<n; i++){
        long long v;
        cin>>v;
        values.push_back({v,i+1});
    }
    sort(values.begin(), values.end());
    int i=0, j=values.size()-1;
    while(i<j){
        if(values[i].first+values[j].first<x) i++;
        else if (values[i].first+values[j].first>x) j--;
        else if(values[i].first+values[j].first==x){
            cout<<values[i].second<<' '<<values[j].second;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}