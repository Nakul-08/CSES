#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto &i : a)cin >> i;
    sort(a.begin(),a.end());
    vector<int>dp(2e5,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(dp[i-1]<a[i-1]){
            cout<< dp[i-1];
            return 0;
        }
        dp[i]=dp[i-1]+a[i-1];
    }
    cout<<dp[n];
}
// //  Let the input array be arr[0..n-1]. We initialize the result as 1 (smallest possible outcome) and traverse the given array. Let the smallest element that cannot be represented by elements at indexes from 0 to (i-1) be ‘res’, there are following two possibilities when we consider element at index i:
// 1) We decide that ‘res’ is the final result: If arr[i] is greater than ‘res’, then we found the gap which is ‘res’ because the elements after arr[i] are also going to be greater than ‘res’.
// 2) The value of ‘res’ is incremented after considering arr[i]: The value of ‘res’ is incremented by arr[i] (why? If elements from 0 to (i-1) can represent 1 to ‘res-1’, then elements from 0 to i can represent from 1 to ‘res + arr[i] – 1’ be adding ‘arr[i]’ to all subsets that represent 1 to ‘res’)
// Following is the implementation of above idea. 
 