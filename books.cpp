#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int32_t main() {
    int n, amount;
    cin >> n >> amount;
    vector<int>price(n);//price
    vector<int>pages(n);//pages
    for (auto &i : price)cin >> i;

    for (auto &i : pages)cin >> i;
    vector<vector<int>>dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][amount];
    return 0;
}