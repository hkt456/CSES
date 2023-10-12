#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    vector<vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<=s1.size();i++){
        for(int j=0; j<=s2.size(); j++){
            if(i!=0){
                dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
            }
            if(j!=0){
                dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
            }
            if(i!=0 && j!=0){
                int new_cost=dp[i-1][j-1]+(s1[i-1]!=s2[j-1]);
                dp[i][j]=min(dp[i][j], new_cost);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];
}