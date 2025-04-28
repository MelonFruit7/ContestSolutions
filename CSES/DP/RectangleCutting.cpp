#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(501, vector<int>(501, 1e9));
int solve(int a, int b) {
    if (a == b) return 0;

    if (a > b) swap(a, b);
    int &res = memo[a][b];
    if (res != 1e9) return res;

    for (int i = 1; i < a; i++) res = min(res, 1+solve(a-i, b)+solve(i, b));
    for (int i = 1; i < b; i++) res = min(res, 1+solve(a, b-i)+solve(a, i));
    return res; 
}

int main() {
    int a, b; cin >> a >> b;
    cout << solve(a, b) << '\n';
    return 0;
}