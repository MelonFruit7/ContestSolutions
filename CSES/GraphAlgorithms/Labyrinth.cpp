#include <bits/stdc++.h>
using namespace std;
#define UP {0, -1}
#define RIGHT {1, 0}
#define DOWN {0, 1}
#define LEFT {-1, 0}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));

    pair<int, int> loc, loc2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'A') loc = {i, j};
            if (board[i][j] == 'B') loc2 = {i, j};
        }
    }
    
    queue<pair<int, int>> q;
    q.push(loc);
    vector<pair<int, int>> dir = {UP, RIGHT, DOWN, LEFT};
    vector<char> letter = {'U', 'R', 'D', 'L'};
    while (!q.empty()) {
        auto [r, c] = q.front();
        if (q.front() == loc2) break;
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> loc3 = {r+dir[i].second, c+dir[i].first};
            if (loc3.first >= 0 && loc3.first < n && loc3.second >= 0 && loc3.second < m) {
                char &slot = board[loc3.first][loc3.second];
                if (slot == '.' || slot == 'B') {
                    slot = letter[i];
                    q.push(loc3);
                }
            }
        }
    }
    
    string res = "";
    map<char, pair<int, int>> mp;
    mp['U'] = DOWN; mp['D'] = UP; mp['R'] = LEFT; mp['L'] = RIGHT;
    if (board[loc2.first][loc2.second] == 'B') {
        cout << "NO" << endl;
        return 0;
    }
    while (loc2 != loc) {
        char c = board[loc2.first][loc2.second];
        res += c;
        auto [x, y] = mp[c];
        loc2.first += y;
        loc2.second += x;
    }
    reverse(res.begin(), res.end());

    cout << "YES" << endl;
    cout << res.size() << endl;
    cout << res << endl;
    return 0;
}