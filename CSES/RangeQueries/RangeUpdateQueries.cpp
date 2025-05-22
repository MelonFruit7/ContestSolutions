#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> nums;
struct node {
    ll val;
    int lo, hi, mid;
    node *left, *right;
    node(int l, int r) {
        lo = l;
        hi = r;
        mid = (lo+hi)/2;
        if (lo == hi) {
            val = nums[mid];
            left = right = nullptr;
            return;
        }
        left = new node(lo, mid);
        right = new node(mid+1, hi);
    }   

    ll query(int idx) {
        if (idx > hi || idx < lo) return 0;
        if (idx == lo && idx == hi) return val;

        if (idx > mid) return right->query(idx)+val;
        return left->query(idx)+val;
    }
    void update(int l, int r, ll v) {
        if (l > hi || r < lo) return;
        if (l <= lo && r >= hi) return void(val += v);
        left->update(l, r, v);
        right->update(l, r, v);  
    }
};

int main() {
    int n, q; cin >> n >> q;
    nums = vector<ll>(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    node segtree(0, n-1);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            ll a, b, u; cin >> a >> b >> u;
            a--;
            b--;
            segtree.update(a, b, u);
        } else if (type == 2) {
            int k; cin >> k;
            k--;
            cout << segtree.query(k) << endl;
        }
    }
    
    return 0;
}