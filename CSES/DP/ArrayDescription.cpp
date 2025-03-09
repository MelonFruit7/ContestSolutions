#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<int>> memo;
int m;
const int MOD = 1e9+7;

int solve(int idx, int num) {
    int &res = memo[idx][num];
    if (idx == nums.size()-1) return res = (nums[idx] == num || nums[idx] == 0);
    if (res != -1) return res;

    res = 0;
    if (nums[idx] != 0 && nums[idx] != num) return 0;
    for (int i = max(num-1, 1); i <= min(num+1, m); i++) res = (res+solve(idx+1, i)) % MOD;    
    return res;
}

int main() {
    int n; cin >> n >> m;
    memo = vector<vector<int>>(n, vector<int>(m+1, -1));

    nums = vector<int>(n, 0);
    for (int &x : nums) cin >> x;

    int res = 0;
    for (int i = 1; i <= m; i++) res = (res+solve(0, i))%MOD; 
    cout << res << endl;
    return 0;
}