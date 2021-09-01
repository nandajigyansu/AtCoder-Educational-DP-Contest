#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, W;
    cin >> N >> W;
    int w[N], v[N];
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<int> > dp(W + 1, vector<int>(N + 1, 0));
    int maxValue = 0;
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j - 1];
            if (w[j - 1] <= i) {
                dp[i][j] = max(dp[i][j], dp[i - w[j - 1]][j - 1] + v[j - 1]);
            }
        }
        maxValue = max(maxValue, dp[i][N]);
    }
    cout << maxValue;
    return 0;
}
