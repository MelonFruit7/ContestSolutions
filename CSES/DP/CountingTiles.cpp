#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
vector<vector<int>> memo;
map<int, vector<int>> transitions;
int n, m; 

int solve(int bitmask, int idx) {
    if (idx == m) {
        if (bitmask == 0) return 1;
        return 0;
    } 
    if (memo[bitmask][idx] != -1) return memo[bitmask][idx];

    vector<int> real = transitions[bitmask];
    int res = 0;
    for (int i = 0; i < real.size(); i++) res = (res+solve(real[i], idx+1))%MOD; 
    return memo[bitmask][idx] = res;
}

int main() {
    cin >> n >> m;
    memo = vector<vector<int>>(pow(2, n), vector<int>(m, -1));

    for (int i = 0; i < (1 << n); i++) {
        transitions[i] = vector<int>();
        for (int j = 0; j < (1 << n); j++) {
            int counter = 0, valid = 1;
            for (int k = 0; k < n; k++) {
                int a = (i>>k) & 1;
                int b = (j>>k) & 1;
                if ((a == 1 && b != 0) || ((a == 1 || b == 1) && counter != 0)) {
                    valid = 0;
                    break;
                }
                if (a == 0 && b == 0) counter = (counter+1)%2;
            }
            if (counter != 0) valid = 0;
            if (valid) transitions[i].push_back(j);
        }
    }
    cout << solve(0, 0) << endl;
    return 0;
}