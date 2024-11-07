#include <bits/stdc++.h>

using namespace std;

struct BIT {
    vector<long long> bit;
    BIT(long long size){
        bit.resize(size);
     }

    void update(long long index, long long delta){
        for(; index<bit.size(); index |= index+1){
            bit[index] += delta;
        }
    }

    void update(long long l, long long r, long long delta){
        update(l, delta);
        update(r+1, -delta);
    }

    long long get(long long i){
        long long res = 0;
        for(; i>=0; i = (i & (i+1)) - 1){
            res += bit[i];
        }
        return res;
    }


};

int main(){
    long long n,q;
    vector<long long> arr;

    cin>>n>>q;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    BIT bit(n);
    long long t,l,r,x;

    while(q--){
        cin>>t;
        if(t==1){
            cin>>l>>r>>x;
            bit.update(l-1, r-1, x);
        }
        else{
            cin>>x;
            cout<<arr[x-1] + bit.get(x-1)<<endl;
        }
    }

    return 0;

}