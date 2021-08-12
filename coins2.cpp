#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int mod = 1e9 + 7;
    int size, amount;
    cin >> size >> amount;
    vector<int>coins(size);
    for (auto &coin : coins)cin >> coin;
    vector<int>dp(amount + 1, 0);
    sort(coins.begin(), coins.end());
    dp[0] = 1;
    for (int i=0;i<size;i++){
        for(int j=coins[i];j<=amount;j++){
            (dp[j]+=dp[j-coins[i]])%=mod;
        }
    }
        // for(auto i:dp)cout<<i<<" ";
        cout << dp[amount] << '\n';

}