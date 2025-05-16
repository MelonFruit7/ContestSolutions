#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<vector<vector<ll>>>> memo(20, vector<vector<vector<ll>>>(10, vector<vector<ll>>(2, vector<ll>(2, -1))));
ll solve(int idx, int prev, bool diverged, bool real_num, string &num) {
    if (idx == 0) return 1;
    if (memo[idx][prev][diverged][real_num] != -1) return memo[idx][prev][diverged][real_num];

    ll ans = 0;
    int mx = diverged ? 9 : num[num.size()-idx]-'0';
    for (int i = 0; i <= mx; i++) {
        if (real_num && i == prev) continue;
        ans += solve(idx-1, i, (i < mx) || diverged, ((i != 0) || real_num), num);
    }
    return memo[idx][prev][diverged][real_num] = ans;
}

int main() {
    ll a, b; cin >> a >> b;
    a -= 1;

    string aa = to_string(a), bb = to_string(b);
    ll full = solve(bb.size(), 0, false, false, bb);
    memo = vector<vector<vector<vector<ll>>>>(20, vector<vector<vector<ll>>>(10, vector<vector<ll>>(2, vector<ll>(2, -1))));
    ll min = solve(aa.size(), 0, false, false, aa);

    cout << (full-min) << endl;
    return 0;
}