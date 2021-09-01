#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; i + j + 1 < n && j < k; j++) {
            dp[i + j + 1] = min(dp[i + j + 1], dp[i] + abs(h[i] - h[i + j + 1]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
