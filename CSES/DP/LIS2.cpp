#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
struct BIT {
    vector<int> b;
    BIT(int n) : b(n+1) {}
    void upd(int i, int v) {for (; i < b.size(); i+=i&-i) b[i] = (b[i]+v)%MOD;}
    int qry(int i) {int s = 0; for (; i; i-=i&-i) s = (s+b[i])%MOD; return s;}
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> cpy = nums;
    sort(cpy.begin(), cpy.end());
    BIT b(n);

    for (int i = 0; i < nums.size(); i++) {
        int l = 0, r = n, res_idx = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (cpy[mid] < nums[i]) {
                res_idx = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        auto it = lower_bound(cpy.begin(), cpy.end(), nums[i]);
        int idx = it-cpy.begin();

        // cout << (1+b.qry(res_idx+1)) << " res_idx: " << res_idx << endl;
        b.upd(idx+1, 1+b.qry(res_idx+1));
    }
    cout << b.qry(n) << endl;
    return 0;
}  