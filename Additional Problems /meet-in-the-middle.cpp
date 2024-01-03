#include <bits/stdc++.h>
using namespace std;
 
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define ll long long 
#define pi pair<ll,ll>

const ll maxN = 1e9+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

class Problem{
public:    

    void run(){
      readInput();
    }
    

    int n,x;
    vector<int> arr(n);
    void readInput(){
      cin>>n>>x;
      for(int i=0; i<n;  i++){
      cin>>arr[i];
      }
    }
    

    auto get_subset_sum = [&](vector<int>& arr){
      int n = arr.size();
      vector<int> subset_sum;
      for(int mask=0; mask<(1<<n); mask++){
        int sum = 0;
        for(int i=0; i<n; i++){
          if(mask&(1<<i)){
            sum += arr[i];
          }
        }
        subset_sum.push_back(sum);
      }
      return subset_sum;
    };
};

int main() {
    fastInputOutput();
    
    Problem solver;
    solver.run(); 
 
    return 0;
}


