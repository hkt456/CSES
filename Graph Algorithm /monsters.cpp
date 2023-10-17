#include <bits/stdc++.h>
using namespace std;

void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}
#define ll long long
#define pi pair<ll, ll>

class Monsters {
public:
    void run() {
        readInput();
        bfsMonstersToEdges();
        bfsPlayerToEdges();
        cout << result;
    }
    ll rlen, clen;
    ll startR, startC;
    deque<pi> monstersLocations;
    vector<vector<ll>> timeMonsters;
    vector<string> grid;
    ll rAdd, cAdd; char direction;
    vector<tuple<ll, ll, char>> dirs = {{0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}, {-1, 0, 'U'}};
    vector<vector<tuple<ll, ll, char>>> previousLocation;
    string result = "NO";

    void readInput() {
        cin >> rlen >> clen;
        grid.resize(rlen);
        timeMonsters.resize(rlen, vector<ll>(clen, INT_MAX));
        previousLocation.resize(rlen, vector<tuple<ll, ll, char>>(clen));
        for (ll r = 0; r < rlen; r++) {
            cin >> grid[r];
            for (ll c = 0; c < clen; c ++) {
                if (grid[r][c] == 'A') {
                    startR = r; startC = c;
                }
                if (grid[r][c] == 'M') {
                    monstersLocations.emplace_back(r, c);
                    timeMonsters[r][c] = 0;
                }
            }
        }
    }

    void bfsMonstersToEdges() {
        while (!monstersLocations.empty()) {
            auto node = monstersLocations.front();
            ll row = node.first, col = node.second;
            monstersLocations.pop_front();
            ll newTime = timeMonsters[row][col] + 1;
            for (auto move: dirs) {
                tie(rAdd, cAdd, direction) = move;
                ll r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= rlen || c < 0 || c >= clen
                    || grid[r][c] == '#' || timeMonsters[r][c] <= newTime)
                    continue;
                timeMonsters[r][c] = newTime;
                monstersLocations.emplace_back(r, c);
            }
        }
    }

    bool isEdge(ll row, ll col) {
        return row == 0 || col == 0 || row == rlen-1 || col == clen-1;
    }
    void bfsPlayerToEdges() {
        deque<tuple<ll, ll, ll>> location;
        location.emplace_back(startR, startC, 0);
        grid[startR][startC] = '#'; // so we don't visit this again.
        previousLocation[startR][startC] = {-1, -1, '*'};
        ll row, col, time;
        while (!location.empty()) {
            tie(row, col, time) = location.front();
            location.pop_front();
            if (isEdge(row, col)) {
                constructPath(row, col);
                return;
            }
            for (auto move: dirs) {
                tie(rAdd, cAdd, direction) = move;
                ll r = row + rAdd, c = col + cAdd;
                ll newTime = time + 1;
                if (grid[r][c] == '#' || timeMonsters[r][c] <= newTime)
                    continue;
                grid[r][c] = '#'; // so we don't visit this again.
                previousLocation[r][c] = {row, col, direction};
                location.emplace_back(r, c, newTime);
            }
        }
    }

    void constructPath(ll row, ll col) {
        result = "YES\n";
        string path;
        while (row != -1) {
            tie(row, col, direction) = previousLocation[row][col];
            path += direction;
        }
        path.pop_back(); // last one is always *
        reverse(path.begin(), path.end());
        result += to_string(path.size());
        result += "\n";
        result += path;
    }
};

int main(){
    fastInputOutput();

    Monsters solution;
    solution.run();

    return 0;
}