#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p = vector<int>(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
        sz = vector<int>(n, 1);
    }
    int find(int a) {
        if (p[a] != a) return p[a] = find(p[a]);
        return a;
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = p[a];
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<string> board(n);
    DSU d(n*m);
    for (int i = 0; i < n; i++) cin >> board[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                res++;
                int idx = i*m+j;
                if (i+1 < n && board[i+1][j] == '.') res -= d.join(idx, idx+m);
                if (j+1 < m && board[i][j+1] == '.') res -= d.join(idx, idx+1);
            }
        }
    }
    cout << res << endl;
    return 0;
}
