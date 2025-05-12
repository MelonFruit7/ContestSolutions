#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> memo(n+2, vector<int>(m+2, 0));
    vector<int> seq1(n), seq2(m);
    for (int i = 0; i < n; i++) cin >> seq1[i];
    for (int i = 0; i < m; i++) cin >> seq2[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if ((i < n && j < m) && seq1[i] == seq2[j]) memo[i+1][j+1] = max(memo[i+1][j+1], memo[i][j]+1);
            memo[i+1][j] = max(memo[i+1][j], memo[i][j]);
            memo[i][j+1] = max(memo[i][j+1], memo[i][j]);
        }
    }
    cout << memo[n][m] << endl;
    string res = "";
    while (n > 0 && m > 0) {
        if (seq1[n-1] == seq2[m-1]) {
            res = to_string(seq1[n-1])+" "+res;
            n--; m--;
        }
        else if (memo[n-1][m] == memo[n][m]) n--;
        else if (memo[n][m-1] == memo[n][m]) m--;
        else if (memo[n-1][m-1] == memo[n][m]) {
            n--; m--;
        }

    }
    cout << res << endl;
    return 0;
}