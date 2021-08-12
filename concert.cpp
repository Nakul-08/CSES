#include <bits/stdc++.h>
using namespace std;
// #define int int64_t
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
        int n,  m,t,s;
        cin >> n >> m;
        multiset<int,greater<int>>tickets;
        while (n--)
    {
        cin >> t;
        tickets.insert(t);
    }

    while (m--)
    {
        cin >> s;
        auto it = tickets.lower_bound(s);
        if (it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            tickets.erase(it);
        }
    }

    }
}