#include <bits/stdc++.h>
using namespace std;

void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define ll long long
#define pi pair<ll,ll>

const ll maxN = 2500+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

class Problem{
public:

    struct Edge{
        ll a, b;
        ll c;
    };

    void run(){
        readInput();
        dfs(1);
        dfsR(n);
        bellmanFord();
        printAnswer();
    }

    int n, m;
    Edge edges[maxN];
    bool vis[maxN], visR[maxN];
    ll dp[maxN];
    vector<ll> G[maxN], GR[maxN]; // Define as vectors

    void readInput(){
        cin>>n>>m;
        for (int i=1; i<=m; i++){
            ll a, b, c;
            cin>>a>>b>>c;
            edges[i] = {a, b, -c};
            G[a].push_back(b); // Use push_back on vectors
            GR[b].push_back(a); // Use push_back on vectors
        }
    }

    void dfs(int u){
        stack<int> s;
        s.push(u);
        vis[u] = true;

        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (int v : G[cur]) {
                if (!vis[v]) {
                    s.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    void dfsR(int u){
        stack<int> s;
        s.push(u);
        visR[u] = true;

        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (int v : GR[cur]) {
                if (!visR[v]) {
                    s.push(v);
                    visR[v] = true;
                }
            }
        }
    }

    void bellmanFord(){
        fill(dp+2, dp+n+1, INF);
        bool isImproving = true;
        for(int i = 1; i <= n && isImproving; i++){
            isImproving = false;
            for(int j = 1; j <= m; j++){
                ll u = edges[j].a;
                ll v = edges[j].b;
                ll w = edges[j].c;
                if(dp[v]>dp[u]+w){
                    dp[v]=dp[u]+w;
                    isImproving = true;

                    if(i==n && vis[v] && visR[v]){
                        cout<<-1<<endl;
                        exit(0);
                    }
                }
            }
        }
    }

    void printAnswer(){
        cout<<-dp[n]<<endl;
    }
};

int main() {
    fastInputOutput();

    Problem solver;
    solver.run();

    return 0;
}
