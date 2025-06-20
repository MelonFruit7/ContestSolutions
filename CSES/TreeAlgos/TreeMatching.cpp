#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> dp;
vector<vector<int>> adjlist;
array<int,2> solve(int u, int p) {
    int res = 0, connected = 0;
    for (int v : adjlist[u]) {
        if (v == p) continue;
        auto s = solve(v, u);
        if (!s[1] && !connected) {
            res++;
            connected = 1;
        }  
        res += s[0];
    }
    return {res, connected};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    dp = vector<array<int, 2>>(n);
    adjlist = vector<vector<int>>(n);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    cout << solve(0, -1)[0] << '\n';
    return 0;
}