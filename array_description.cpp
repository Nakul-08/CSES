#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int mod=1000000007;
    int n, m;
    cin >> n >> m;
    vector<vector<int>>dp(n, vector<int>(m + 1, 0));
    int x;
    cin >> x;
    if (x == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else {
        dp[0][x] = 1;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int y; cin >> y;
        if (y == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : {j - 1, j, j + 1}) {
                    if (k <= m && k >= 1) {
                        (dp[i][j] += dp[i - 1][k]%mod) %=mod;
                    }
                }
            }
        }
        else {
            for (int k : {y - 1, y, y + 1}) {
                if (k <= m && k >= 1) {
                    (dp[i][y] += dp[i - 1][k]%mod) %=mod;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        (ans += dp[n - 1][i]) %=mod;
    }
    cout << ans;
}