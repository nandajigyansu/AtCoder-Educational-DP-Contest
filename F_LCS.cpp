#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    int m = s.length();
    int n = t.length();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    if (maxLen == 0) {
        cout << " " << endl;
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == maxLen) {
                x = i;
                y = j;
            }
        }
    }
    vector<char> v;
    while (dp[x][y] != 0) {
        if (s[x - 1] == t[y - 1]) {
            v.push_back(s[x - 1]);
            x--;
            y--;
        }
        else {
            if (dp[x][y] == dp[x - 1][y]) {
                x--;
            }
            else {
                y--;
            }
        }
    }
    reverse(v.begin(), v.end());
    for (auto c : v) {
        cout << c;
    }
    cout << endl;
    return 0;
}
