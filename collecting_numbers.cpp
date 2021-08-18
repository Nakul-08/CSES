#include <bits/stdc++.h>
using namespace std;
int main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int>a(n);
    int ans = 1;
    map<int, int>mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 1; i <= n - 1; i++) {
        ans+= (mp[i]>mp[i + 1]?1:0);
    }
    cout << ans;
}
//one thing to note that we need to collect number 1 to n in increasing order or in 1 2 3 4 .. not in 1 3 2 etc.
//so in this question we only care about the x and x-1 values as x must come after x-1