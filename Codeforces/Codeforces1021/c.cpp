#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> days(n);
        for (int &day : days) cin >> day;
        sort(days.begin(), days.end());

        int day = -1, amount = 0;
        int known_day = -1;

        bool passed = false;
        for (int i = 0; i < days.size(); i++) {
            if (days[i] == day) amount++;
            if (days[i] != day) {
                if (amount == 1 && known_day==day+1) known_day = day+2;
                day = days[i];
                amount = 1;
            }
            if ((amount >= 2 && known_day==day+1) || amount >= 4) {
                passed = true;
                break;
            } 
            if (amount >= 2) known_day = day+2;
        }
        if (passed) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}