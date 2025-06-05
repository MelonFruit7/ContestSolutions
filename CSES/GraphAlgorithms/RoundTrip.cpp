#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> adjlist;

int loop_node = -1;
vector<int> find_cycle(int node, int parent) {
    for (int i = 0; i < adjlist[node].size(); i++) {
        int other_node = adjlist[node][i];

        if (other_node == parent) continue;
        if (visited[other_node] != -1) {
            loop_node = other_node;
            return {other_node, node};
        }
        visited[other_node] = 1;
        auto res = find_cycle(other_node, node);
        if (res.size() > 0 && loop_node != -1) {
            if (node == loop_node) loop_node = -1;
            res.push_back(node);
            return res;
        } else if (res.size() > 0) {
            return res;
        }
    }
    return {};
}

int main() {
    int n, m; cin >> n >> m;
    adjlist = vector<vector<int>>(n);
    visited = vector<int>(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        loop_node = -1;
        if (visited[i] == 1) continue;
        visited[i] = 1;
        auto res = find_cycle(i, -1);
        if (res.size() > 0) {
            cout << res.size() << endl;
            reverse(res.begin(), res.end());
            for (int item : res) cout << (item+1) << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}