#include <bits/stdc++.h>
using namespace std;

struct node {
    bool word;
    vector<node*> children;
    node() {
        word = false;
        children = vector<node*>(26, nullptr);
    }

    void insert_word(string &str, int idx) {
        if (idx == str.size()) return void(word = true);
        if (!children[str[idx]-'a']) children[str[idx]-'a'] = new node();
        children[str[idx]-'a']->insert_word(str, idx+1);
    }
};

const int MOD = 1e9+7;
vector<int> memo;
node root;

int solve(string &str, int idx) {
    int og_idx = idx;
    int res = 0;
    node *n = root.children[str[idx]-'a'];
    while (n != nullptr) {
        idx++;
        if (n->word) res = (res+(memo[idx]))%MOD;
        if (idx == str.size()) break;
        n = n->children[str[idx]-'a'];
    }
    return memo[og_idx] = res;   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string str; cin >> str;
    memo = vector<int>(str.size()+1, 0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        root.insert_word(s, 0);
    }
    memo[str.size()] = 1;
    for (int i = str.size()-1; i >= 0; i--)
        solve(str, i);
    cout << memo[0] << endl;
    return 0;
}