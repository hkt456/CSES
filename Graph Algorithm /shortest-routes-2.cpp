#include <bits/stdc++.h>
using namespace std;
 
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define ll long long 
#define pi pair<ll,ll>

const ll maxn = 500+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;


class Problem{
public:    
    void run(){
        readInput();
        floydMarshall();
        printAnswer();
    }

    ll n,m,q,a,b;
    ll dist[maxn][maxn], c;


    void readInput(){
        cin>>n>>m>>q;
        memset(dist, 0x3f, sizeof(dist));
        for(int i=0; i<m; i++){
            cin>>a>>b>>c;
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);
        }
        for(int i = 0; i<n; i++){
            dist[i][i] = 0;
        }

    }

    void floydMarshall(){
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    void printAnswer(){
        for(int i = 0; i < q; i++){
            cin>>a>>b;
            // if(dist[a][b] == 0x3f) cout<<dist[a][b]<<" ";
            cout << (dist[a][b] >= INF ? -1 : dist[a][b]);
            cout<<endl;
        }
    }
};

int main() {
    fastInputOutput();
    
    Problem solver;
    solver.run(); 
 
    return 0;
}
