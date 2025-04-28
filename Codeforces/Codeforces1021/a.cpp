#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        stack<int> next;
        vector<int> freq(10, 0);
        for (char c : s) freq[c-'0']++;

        string res = "";
        for (int i = 9; i >= 0; i--) {
            if (freq[i] > 0) {
                res += i+'0';
                freq[i]--;
            } else {
                res += next.top()+'0';
                next.pop();
            }

            while (freq[i] > 0) {
                next.push(i);
                freq[i]--;
            }
        } 
        cout << res << endl;
    }
    return 0;
}