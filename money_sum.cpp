#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto &i : a)cin >> i;
    int max_sum = accumulate(a.begin(), a.end(), 0);
    vector<vector<bool>>dp(n+1, vector<bool>(max_sum + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= max_sum; j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = 1;
            }
            else if (i == 0) {
                dp[i][j] = 0;
            }
            else if (j == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = (dp[i - 1][j]);
                if(j>=a[i-1]){
                    dp[i][j]=(dp[i][j]|dp[i-1][j-a[i-1]]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_sum; i++) {
        if (dp[n][i] == 1)ans++;
    }
    cout<<ans<<'\n';
    for(int i=1;i<=max_sum;i++){
        if(dp[n][i]==1){
            cout<<i<<" ";
        }
    }
}