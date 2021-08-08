#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define mod 1000000007
#define lcm(a,b) (a*b)/__gcd(a,b)
void fast()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return 0;
    }();
}
bool isprime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}
// vector<int>parent(1000006);
// vector<int>rk(1000006);
// int findparent(int node) {
//     if (node == parent[node])return node;
//     return parent[node] = findparent(parent[node]);
// }
// void un(int a, int b) {
//     a = findparent(a);
//     b = findparent(b);
//     if (a != b) {
//         rk[a] += rk[b];
//         parent[b] = a;
//     }
// }
int power(int x, int y)
{
    int res = 1;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % (int)mod;
        y = y >> 1;
        x = (x * x) % (int)mod;
    }
    return res;
}
int32_t main() {
    fast();
    int tt;
    tt = 1;
    while (tt--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int>a(n, 0);
        for (auto &i : a)cin >> i;
        vector<int>b(m, 0);
        // cout<<1<<endl;
        for (auto &i : b)cin >> i;
        sort(a.begin(), a.end());
        int ans = 0;
        sort(b.begin(), b.end());
        int j = 0, i = 0;
        while (i < n && j < m) {
            if(abs(a[i]-b[j])<=x){
                ans++;
                i++;
                j++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else{
                i++;
            }
        }
        cout<<ans<<'\n';

    }
}