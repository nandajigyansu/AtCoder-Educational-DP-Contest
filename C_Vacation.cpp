#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a, b, c, aa, bb, cc, p, q, r;
    cin >> a >> b >> c;
    for (int i = 1; i < n; i++) {
        cin >> aa >> bb >> cc;
        p = max(b, c) + aa;
        q = max(a, c) + bb;
        r = max(a, b) + cc;
        a = p;
        b = q;
        c = r;
    }
    cout << max(max(a, b), c);
    return 0;
}
