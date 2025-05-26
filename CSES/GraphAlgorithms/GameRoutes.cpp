#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int main() {
    int n, m; cin >> n >> m;
    vector<int> indeg(n, 0);
    vector<vector<int>> adj_list(n);
    vector<int> memo(n, 0); memo[0] = 1;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        indeg[b]++;
        adj_list[a].push_back(b);
    }
    queue<int> q;
    for (int i = 0; i < indeg.size(); i++) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        vector<int> paths = adj_list[node];
        for (int i = 0; i < paths.size(); i++) {
            memo[paths[i]] = (memo[paths[i]]+memo[node])%MOD;
            int val = --indeg[paths[i]];
            if (!val) q.push(paths[i]); 
        }
    }
    cout << memo[n-1] << endl;
    return 0;
}