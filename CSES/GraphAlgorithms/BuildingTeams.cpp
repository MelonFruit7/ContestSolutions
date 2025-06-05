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

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            queue<int> q;
            q.push(i);
            visited[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int j = 0; j < adjlist[node].size(); j++) {
                    int other_node = adjlist[node][j];
                    if (visited[other_node] != -1) {
                        if (visited[other_node] != (visited[node]+1)%2) {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                        continue;
                    }
                    visited[other_node] = (visited[node]+1)%2;
                    q.push(other_node);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (visited[i]+1) << " ";
    }
    cout << endl;
    return 0;
}