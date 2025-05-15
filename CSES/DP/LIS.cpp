#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    set<int> res;
    for (int i = 0; i < n; i++) {
        auto lb = res.lower_bound(nums[i]);
        if (lb == res.end()) res.insert(nums[i]);
        else {
            res.erase(*lb);
            res.insert(nums[i]);
        }
    }
    cout << res.size() << endl;
    return 0;
}