#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>num[i];
        sum+=num[i];
    }
    vector<vector<long long> > dp(n, vector<long long>(n));
    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(j==i)   dp[i][j]=num[j];
            else{
                dp[i][j]=max(num[i]-dp[i+1][j], num[j]-dp[i][j-1]);
            }
        }
    }
    cout<<(sum+dp[0][n-1])/2;
}