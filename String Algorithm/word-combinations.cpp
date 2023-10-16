#include <bits/stdc++.h>
using namespace std;


string str;
const long long mod = 1e9+7;

struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0; i<26; i++) child[i]=NULL;
    }
};

TrieNode *root;

void insertString(string st){
    TrieNode *curr = root;
    int n = st.size();
    for (int i = 0 ; i <n; ++i) {
        int index = st[i]-'a';
        if(curr->child[index]==NULL){
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

void solve(){
    int n;
    cin>>n;
    root= new TrieNode();
    for(int i=0; i<n; i++){
        string st;
        cin>>st;
        insertString(st);
    }
    int len = str.length();
    vector<int> dp(len+1);
    dp[len]=1;
    for(int i=len-1; i>=0; i--){
        TrieNode *test = root;
        for(int j = i; j<len; j++){
            int index = str[j]-'a';
            if(test->child[index]==NULL) break;
            test = test->child[index];
            if(test->isEnd){
                dp[i]=dp[i]%mod + dp[j+1];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp[0];
}

int main(){
    cin>>str;
    solve();
}