#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int mod = 1e9 + 7;
    int number;
    cin >> number;
    vector<int>dp(number+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=number;i++){
        for(auto c:to_string(i)){
            dp[i]=min(dp[i],dp[i-(c-'0')]+1);
        }
    }
 cout<<dp[number];
}