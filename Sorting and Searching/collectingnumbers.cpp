#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int main(){
    int n; cin>>n;
    int l = 1;
    int ind[n+1];
    memset(ind, (int)0, sizeof(ind));
    for (int i = 1; i <= n; i++) {
    	int x; cin>>x;
    	ind[x] = i;
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
    	if (l > ind[i]) 
    		c++;
    	l = ind[i];
    }
    cout<<c;
}