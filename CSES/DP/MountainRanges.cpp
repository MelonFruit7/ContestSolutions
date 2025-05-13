#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

template<class T, class C = less<T>> struct RMQ {
  vector<vector<T>> t;
  C cmp;
  RMQ(vector<T> a, C cmp = C{}):
    t(__lg(sz(a)) + 1, a), cmp(cmp) {
    for (int k = 1, len = 1; k < sz(t); k++, len <<= 1)
      for (int i = 0; i + 2 * len - 1 < sz(a); i++)
        t[k][i] = min(t[k - 1][i], t[k - 1][i + len], cmp); }
  T query(int a, int b) { // inclusive-exclusive [a, b)
    int k = __lg(b - a), len = 1 << k;
    return min(t[k][a], t[k][b - len], cmp); } };

vector<int> memo;
vector<pair<int, int>> mountains;
RMQ<pair<int, int>, greater<pair<int, int>>> r((vector<pair<int, int>>){});
int solve(int idx, int lrange, int rrange) {
    if (lrange >= rrange || idx == -1) return 0;
    if (memo[idx] != -1) return memo[idx];
    int res1 = 0, res2 = 0;
    int suml = 1, sumr = 1;

    if (idx-lrange > 0) {
        auto left = r.query(lrange, idx);
        if (mountains[idx].first == left.first || left.first == -1) suml--;
        res1 = suml+solve(left.second, lrange, idx);
    }

    if (rrange-(idx+1) > 0) {
        auto right = r.query(idx+1, rrange);
        if (mountains[idx].first == right.first || right.first == -1) sumr--;
        res2 = sumr+solve(right.second, idx+1, rrange);
    }
    return memo[idx] = max(res1, res2);
}

int main() {
    int n; cin >> n;
    memo = vector<int>(n, -1);
    mountains = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++) {
        cin >> mountains[i].first;
        mountains[i].second = i;
    }
    r = RMQ<pair<int, int>, greater<pair<int, int>>>(mountains, greater<pair<int, int>>());
    cout << (1+solve(r.query(0, n).second, 0, n)) << endl;
    return 0;
}