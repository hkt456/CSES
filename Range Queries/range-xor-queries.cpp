#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)

using namespace std;
 
const int N = 200001;
int ar[N];
 
int main()
{
	int n , q , a , b;
	cin>>n>>q;
	
	REP(i , n) cin>>ar[i] , ar[i] ^= ar[i-1];
	
	while(q--)
	{
		cin>>a>>b;
		cout<<(ar[b] ^ ar[a-1])<<endl;
	}
}
 