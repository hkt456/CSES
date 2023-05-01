#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=0; i<n; i++){
        string row;
        cin>>row;
        for(int j=0; j<row.size();j++){
            if(row[j]=='*') dp[i][j]=0;
            else{
                if(i>0) (dp[i][j]+=dp[i-1][j])%=md;
                if(j>0) (dp[i][j]+=dp[i][j-1])%=md;
            }
        }
    }
    cout<<dp[n-1][n-1];
}