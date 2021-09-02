#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(vector<int>* g, vector<bool>& vis, vector<int>& dp, int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(g, vis, dp, v);
        }
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> dp(n + 1, 0);
    vector<bool> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(g, vis, dp, i);
        }
    }
    int maxLength = 0;
    for (int i = 1; i <= n; i++) {
        maxLength = max(maxLength, dp[i]);
    }
    cout << maxLength;
    return 0;
}
