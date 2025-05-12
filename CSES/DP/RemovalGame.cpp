#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> numbers;
vector<vector<ll>> memo;
ll solve(int idx1, int idx2, int turn) {
    if (idx1 > idx2) return 0;

    ll &res = memo[idx1][idx2];
    if (res != -1e18) return res;
    int next_turn = (turn+1)%2;

    int num1 = numbers[idx1], num2 = numbers[idx2];
    if (turn == 0) {
        return res = max(numbers[idx1]+solve(idx1+1, idx2, next_turn), numbers[idx2]+solve(idx1, idx2-1, next_turn));
    } else {
        return res = min(solve(idx1+1, idx2, next_turn), solve(idx1, idx2-1, next_turn));
    }
}

int main() {
    int n; cin >> n;
    numbers = vector<ll>(n);
    memo = vector<vector<ll>>(n, vector<ll>(n, -1e18));
    for (int i = 0; i < n; i++) cin >> numbers[i];
    cout << solve(0, n-1, 0) << endl;
    return 0;
}