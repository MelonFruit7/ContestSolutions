#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> memo;
vector<vector<ll>> projects;
auto lm = [](const vector<ll> &a, const vector<ll> &b) {return a[0]<b[0];};
ll solve(int idx) {
    if (idx == projects.size()) return 0;
    if (memo[idx] != -1) return memo[idx];

    vector<ll> test = {projects[idx][1]+1};
    auto it = lower_bound(projects.begin(), projects.end(), test, lm);
    int next_valid = it-projects.begin();

    return memo[idx] = max(projects[idx][2]+solve(next_valid), solve(idx+1));
}

int main() {
    int n; cin >> n;
    memo = vector<ll>(n, -1);
    projects = vector<vector<ll>>(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        int s, e, r; cin >> s >> e >> r;
        projects[i] = {s, e, r};
    }
    sort(projects.begin(), projects.end(), lm);
    cout << solve(0) << endl;
    return 0;
}