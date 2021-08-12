#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int mod=1e9+7;
    int size, amount;
    cin>>size>>amount;
    vector<int>coins(size);
    for (auto &coin : coins)cin >> coin;
    vector<int>dp(amount + 1, 0);
    sort(coins.begin(), coins.end());
    dp[0] = 1;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < size; j++) {
            if(coins[j]>i)continue;
            (dp[i]+=dp[i-coins[j]])%=mod;
        }
    }
    // for(auto i:dp)cout<<i<<" ";
    cout<<dp[amount]<<'\n';

}