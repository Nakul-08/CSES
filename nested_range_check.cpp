#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct pairs {
    int left, right, pos;
    bool operator <(const pairs & next) const
    {
        if (left == next.left)return right > next.right;
        return left < next.left;
    }
};
int32_t main() {
    int n;
    cin >> n;
    vector<pairs>a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i].left = x;
        a[i].right = y;
        a[i].pos = i;
    }
    vector<int>ans1(n, 0);
    int l_max = -1;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].right <= l_max) {
            ans1[a[i].pos] = 1;
        }
        l_max = max(l_max, a[i].right);
    }
    int r_min = 1e10;
    vector<int>ans2(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].right >= r_min) {
            ans2[a[i].pos] = 1;
        }
        r_min = min(r_min, a[i].right);
    }
    for (auto i : ans2)cout << i << " ";
    cout << '\n';
    for (auto i : ans1)cout << i << " ";

}


