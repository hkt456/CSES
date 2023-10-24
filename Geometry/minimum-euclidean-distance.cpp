#include <bits/stdc++.h>
using namespace std;
 
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define ll long long 
#define pi pair<ll,ll>

const ll maxN = 1e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

class Problem{
public:    
    
    void run(){
      readInput();
    }
    

    int n;
    vector<pi> points;
    vector<pi> temp;
    void readInput(){
      cin>>n;
      points.assign(n, {0,0});
      for(int i=0; i<n; i++){
        cin>>points[i].first>>points[i].second; 
      }
      sort(points.begin(), points.end());
    }
    

    int distance(pi a, pi b){
      int x = a.first-b.first, y = a.second-b.second;
      return x*x+y*y;
    }
    
    bool cmp(pi a, pi b){
      return a.second < b.second;
    }
    
    int solve(int l, int r){
      if(l==r) return INT_MAX;
      int mid = (l + r) / 2,mid_x = points[mid].first;
      int ans = min(solve(l,mid),solve(mid+1,r));
    
      temp.assign(r - l + 1,{0 , 0});
      merge(
          points.begin() + l,points.begin() + mid + 1,
          points.begin() + mid + 1,points.begin() + r + 1,
          temp.begin(), cmp
      );
      for(int i=l;i<=r;i++)points[i] = temp[i-l];
      temp.clear();
      for(int i=l;i<=r;i++){
          if(abs(points[i].first - mid_x)*abs(points[i].first - mid_x) <= ans)temp.push_back(points[i]);
      }
      int len = temp.size();
      for(int i = 0;i < len;i++){
        for(int j = i+1;j < len;j++){
            ans = min(ans,distance(temp[i],temp[j]));
            if(abs(temp[i].second - temp[j].second)*abs(temp[i].second - temp[j].second) > ans)break;
        }
      }
      return ans;
    }
    
    void print_answer(){
      cout<<solve(0,n-1)<<"\n";  
    }
};

int main() {
    fastInputOutput();
    
    Problem solver;
    solver.run(); 
 
    return 0;
}


