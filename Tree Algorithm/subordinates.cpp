#include <bits/stdc++.h>
using namespace std;

#define maxN 202020

vector<vector<int>> adj(maxN);
vector<int> numOfSub(maxN);

int solve(int node){
    if(adj[node].size()==0) return 1;
    else{
        for(int i=0; i<adj[node].size(); i++){
            numOfSub[node]+=solve(adj[node][i]);
        }
    }
    return numOfSub[node]+1;
}

int main(){
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    solve(1);
    for(int i=1; i<=n ;i++) cout<<numOfSub[i]<<" ";
    return 0;
}
