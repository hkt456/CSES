#include <bits/stdc++.h>
using namespace std;

void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define ll long long 
#define pi pair<ll,ll>

const ll maxN = 1e5+5;

class Problem{
public:    
    struct Edge{
        ll v;
        ll w;
    };

    struct Node{
        ll index, dist;
        friend bool operator<(const Node &a, const Node &b) {
            return a.dist > b.dist;
        }
    };

    ll n, m, a, b, c;
    vector<Edge> G[maxN];
    ll dist[maxN];
    priority_queue<Node> Q;

    void run(){
        readInput();
        dijkstra();
        print_answer();
    }

    void readInput(){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            G[a].push_back({b, c});
        }
    }

    void dijkstra(){
        for(int i = 1; i <= n; i++) {
            dist[i] = LLONG_MAX; // Initialize with a large value
        }
        dist[1] = 0;
        Q.push({1, 0});
        while(!Q.empty()){
            ll d = Q.top().dist;
            ll u = Q.top().index;
            Q.pop();

            if(d > dist[u]) continue;

            for(Edge e : G[u]){
                if(dist[e.v] > d + e.w){
                    dist[e.v] = d + e.w;
                    Q.push({e.v, d + e.w});
                }
            }
        }
    }

    void print_answer(){
        for(int i = 1; i <= n; i++){
            cout << dist[i] << " ";
        }
    }
};

int main() {
    fastInputOutput();
    
    Problem solver;
    solver.run(); 
 
    return 0;
}
