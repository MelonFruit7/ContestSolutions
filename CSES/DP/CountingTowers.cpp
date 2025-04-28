
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    vector<int> memo(1e6+1);
    int n = 1e6;

    ll total = 2;
    ll prev_top_split = 0, prev_top_combined = 0;
    ll top_split = 1, top_combined = 1;
    while (--n) {
        memo[1e6-n] = total;

        prev_top_split = top_split%MOD;
        prev_top_combined = top_combined%MOD;

        top_split = total;
        top_combined = total;
        total *= 2;

        top_split += prev_top_split*3;
        top_combined += prev_top_combined;

        total = top_split+top_combined;
        total %= MOD;
    }
    memo[1e6] = total;

    while (t--) {
        int n; cin >> n;
        cout << memo[n] << "\n";
    }
    return 0;
}