#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
int previousSteps[1005][1005];
string direction="LURD";

int dX[4]={-1,0,1,0};
int dY[4]={0,-1,0,1};
int n,m;
bool isValid(int y,int x){
    if(grid[y][x]=='#') return false;
    if(y<0||x<0||y>=n||x>=m) return false;
    if(visited[y][x]) return false;
    return true;
}

int main(){  
    cin>>n>>m;
    pair<int,int> start;
    pair<int,int> finish;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start=make_pair(i,j);
            else if(grid[i][j]=='B') finish=make_pair(i,j);
        }
    }
    q.push(make_pair(start.first, start.second));
    visited[start.first][start.second]=true;
    while(!q.empty()){
        pair<int,int> consider= q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int,int> newTitle=make_pair(consider.first+dY[i],consider.second+dX[i]);
            if(isValid(newTitle.first,newTitle.second)){
                visited[newTitle.first][newTitle.second]=true;
                previousSteps[newTitle.first][newTitle.second]=i;
                q.push(newTitle);
            }
        }
    }
     if(visited[finish.first][finish.second]){
        cout<<"YES"<<endl;
        vector<int> steps;
        while(finish!=start){
            int num=previousSteps[finish.first][finish.second];
            steps.push_back(num);
            finish=make_pair(finish.first-dY[num],finish.second-dX[num])
            ;
        }
        reverse(steps.begin(),steps.end());
        cout<<steps.size()<<endl;
        for(int i=0; i<steps.size(); i++){
            cout<<direction[steps[i]];
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}