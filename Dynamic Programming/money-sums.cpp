#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int maxSum=1000*n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        coins[i]=num;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(maxSum + 1, false));
    dp[0][0]=true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=maxSum; j++){
            dp[i][j]=dp[i-1][j];
            int left = j-coins[i-1];
            if(left>=0 && dp[i-1][left]){
                dp[i][j]=true;
            }
        }
    }
    vector<int> possible;
    for (int j = 1; j <= maxSum; j++) {
        if (dp[n][j]) {
        possible.push_back(j);
        }
    }
    cout << possible.size() << endl;
    for (int v : possible) {
        cout << v << ' ';
    }
    cout << endl;
}