#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>

vector<int> people;
vector<pii> memo;
int n, k;

pii solve(int bitmask) {
    if (bitmask == pow(2, n)-1) return {0, 0};
    if (memo[bitmask].first != -1) return memo[bitmask];
    int bitmask_copy = bitmask;

    pii ans = {1e9, 1e9};
    for (int i = 0; i < n; i++) {
        
        if (!(bitmask & (1<<i))) {
            bitmask ^= (1<<i);
            pii res = solve(bitmask);
            if (res.second+people[i] > k) {
                res.first += 1;
                res.second = people[i];
            } else {
                res.second += people[i];
            }
            if (ans.first > res.first) ans = res;
            else if (ans.second > res.second) ans = res;
        }
        bitmask = bitmask_copy;
    }
    return memo[bitmask] = ans;
}

int main() {
    cin >> n >> k;
    people = vector<int>(n);
    memo = vector<pii>(pow(2, n), {-1, -1});

    for (int i = 0; i < n; i++) cin >> people[i];

    int bitmask = 0;
    pii res = solve(bitmask);
    if (res.second > 0) res.first += 1;
    cout << res.first << endl;
    return 0;
}