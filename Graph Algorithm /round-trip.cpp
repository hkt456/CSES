#include <bits/stdc++.h>
using namespace std;
 
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

class RoundTrip{
public:
    bool found = false;
    void run(){
        readInput();
        findCycle();
        if(!found) cout<<"IMPOSSIBLE"<<endl;
    }
    int n,m;
    vector<vector<int> > adj;
    void readInput(){
        cin>>n>>m;
        adj = vector<vector<int> > (n+1);
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<bool> vis;
    void findCycle() {
        vis = vector<bool>(n + 1);
        for (int i = 1; i < n + 1; i++) {
            if (vis[i]) continue;
            vector<int> path;
            dfs(i, -1, path);
        }
    }
    void dfs(int node, int parent, vector<int> &path) {
        if (found) return;
        if (vis[node]) {
            if (path.size() > 2)
                printResult(node, path);
            return;
        }
        vis[node] = true; 
        path.push_back(node);
        for (auto child: adj[node]) {
            if (child == parent) continue;
            dfs(child, node, path);
        }
        path.pop_back();
    }
     void printResult(int node, vector<int> &path) {
        found = true;
        int count = 1;
        string result = "";
        result += to_string(node) + " ";
        for (int i = path.size() - 1; i >= 0; i--) {
            result += to_string(path[i]);
            count++;
            if (path[i] == node)
                break;
            else
                result += " ";
        }
        cout << to_string(count) << "\n" << result << endl;
    }
};

int main() {
    fastInputOutput();
    RoundTrip solver;
    solver.run();
    return 0;
}
