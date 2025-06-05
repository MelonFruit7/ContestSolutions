#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> visited(n, -1);
    vector<vector<int>> adjlist(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    visited[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == n-1) break;
        
        for (int i = 0; i < adjlist[node].size(); i++) {
            int other_node = adjlist[node][i];
            if (visited[other_node] != -1) continue;
            visited[other_node] = node;
            q.push(other_node);
        }
    }

    if (visited[n-1] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    stack<int> res;

    int route = n-1;
    res.push(route);
    while (route != 0) {
        route = visited[route];
        res.push(route);
    }

    cout << res.size() << endl;
    while (!res.empty()) {
        cout << (res.top()+1) << " ";
        res.pop();
    }
    return 0;
}