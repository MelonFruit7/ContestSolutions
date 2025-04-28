#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int &num : nums) cin >> num;

    vector<int> memo(1e5+1, 0);
    vector<int> memo2(1e5+1, 0);
    memo[0] = 1;
    memo2[0] = 1;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        for (int j = 1; j < memo.size(); j++) {
            if (j-num < 0) continue;
            if (memo[j-num] == 1) {
                memo2[j] = 1;
            }
        }
        memo = memo2;
    }

    vector<int> res;
    for (int i = 1; i < memo.size(); i++) if (memo[i] == 1) res.push_back(i);
    
    cout << res.size() << endl;
    for (int num : res) cout << num << " ";
    cout << endl;
    
    return 0;
}