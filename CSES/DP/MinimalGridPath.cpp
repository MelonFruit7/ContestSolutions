#include <bits/stdc++.h>
using namespace std;
#define MOVE_RIGHT 0
#define MOVE_DOWN 1

vector<vector<int>> memo;
vector<vector<char>> board;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    board = vector<vector<char>>(n, vector<char>(n));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> board[i][j];
    vector<char> res(n*2-1, 'Z');

    queue<pair<int, int>> look_at;
    vector<pair<int, int>> next;
    next.push_back({0, 0});

    int counter = 0;
    while (!next.empty()) {
        sort(begin(next), end(next));
        next.erase(unique(begin(next), end(next)), end(next));
        for (auto p : next) look_at.push(p);
        next.clear();

        while (!look_at.empty()) {
            auto c = look_at.front();
            look_at.pop();
            
            if (res[counter] > board[c.first][c.second] || res[counter] == board[c.first][c.second]) {
                if (res[counter] > board[c.first][c.second]) {
                    res[counter] = board[c.first][c.second];
                    next.clear();
                }
                if (c.first < board.size()-1) next.push_back({c.first+1, c.second});
                if (c.second < board.size()-1) next.push_back({c.first, c.second+1});
            }
        }
        counter++;
    }
    cout << string(res.begin(), res.end()) << endl;
    return 0;
}