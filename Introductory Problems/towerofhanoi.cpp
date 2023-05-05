#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c, int n) {
	if (n == 0)
		return;
	solve(a, c, b, n-1);
	cout<<a<<' '<<c<<endl;
	solve(b, a, c, n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(1,2,3,n);
}