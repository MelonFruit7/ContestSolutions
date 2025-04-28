#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> bars(n);
        for (int &bar : bars) cin >> bar;
        sort(bars.begin(), bars.end());

        int idx1, idx2;
        int res = 1;
        if (n%2 == 1) {
            if (k > 0) {
                k--;
                idx1 = n/2-1;
                idx2 = n/2+1;
                res = bars[idx2]-bars[idx1]+1;
            }
        } else {
            idx1 = n/2-1;
            idx2 = n/2;
            res = bars[idx2]-bars[idx1]+1;
        }
        while (k > 1) {
            idx1--;
            idx2++;
            res = bars[idx2]-bars[idx1]+1;
            k -= 2;
        }
        cout << res << endl;
    }
    return 0;
}