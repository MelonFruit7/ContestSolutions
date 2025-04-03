#include <bits/stdc++.h>
using namespace std;

string s1, s2; 
vector<vector<int>> memo;
int solve(int idx1, int idx2) {
    if (idx1 == s1.size()) return s2.size()-idx2;
    if (idx2 == s2.size()) return s1.size()-idx1;

    if (memo[idx1][idx2] != -1) return memo[idx1][idx2];
    
    int add = 1+solve(idx1, idx2+1);
    int replace = (s1[idx1] != s2[idx2])+solve(idx1+1, idx2+1);
    int rem = 1+solve(idx1+1, idx2);

    memo[idx1][idx2] = min(rem, min(add, replace));
    return memo[idx1][idx2];
}

int main() {
    cin >> s1 >> s2;
    memo = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
    cout << solve(0, 0) << endl;
    return 0;
}