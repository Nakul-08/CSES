#include <bits/stdc++.h>
using namespace std;
int main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<long long>a(n);
    long long mid=0;
    for (auto &i : a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    mid=a[n/2];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        (ans += abs(mid - a[i]));
    }
    cout << ans;
}