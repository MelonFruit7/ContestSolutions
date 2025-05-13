#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
vector<vector<int>> memo;
int n;
int solve(int fill1, int fill2, int idx) {
    if (idx == n+1) return fill1==fill2;

    if (memo[idx][fill1] != -1) return memo[idx][fill1];

    int ans1 = solve(fill1+idx, fill2, idx+1) % MOD;
    int ans2 = solve(fill1, fill2+idx, idx+1) % MOD;
    int sum = (ans1+ans2)%MOD;
    return memo[idx][fill1] = sum;
}
int main() {
    cin >> n;
    memo = vector<vector<int>>(n+1, vector<int>(n*n, -1));
    cout << solve(1, 0, 2) << endl;
    return 0;
}