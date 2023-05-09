#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a, pair<int,int> &b){
    return (a.second<b.second);
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> times;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        times.push_back({start, end});
    }
    sort(times.begin(), times.end(), cmp);
    int movies=0, currentEndTime=-1;
    for(int i=0; i<n; i++){
        if(currentEndTime<=times[i].first){
            movies++;
            currentEndTime=times[i].second;
        }
    }
    cout<<movies;
    return 0;
}