#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}
