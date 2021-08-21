#include<bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>segtree((1 << 22), 0);
vector<int>lazy((1 << 22), 0);
void build(int index, int i, int j, vector<int>&a) {
    if (i > j)return;
    if (i == j) {
        segtree[index] = a[i];
        return;
    }
    int mid = i + (j - i) / 2;
    build(2 * index + 1, i, mid, a);
    build(2 * index + 2, mid + 1, j, a);
}
void lazyupdate(int l, int r, int value, int index, int i, int j) {
    if (lazy[index] != 0) {
        segtree[index] += lazy[index];
        if (i != j) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (i > r || j < l)return;
    if (i >= l && j <= r) {
        segtree[index] += value;
        if (i != j) {
            lazy[(2 * index) + 1] += value;
            lazy[(2 * index) + 2] += value;
        }
        return;
    }
    int mid = i + (j - i) / 2;
    lazyupdate(l, r, value, 2 * index + 1, i, mid);
    lazyupdate(l, r, value, 2 * index + 2, mid + 1, j);
}
int getans(int k, int i, int j, int index) {
    if (lazy[index] != 0) {
        segtree[index] += lazy[index];
        if (i != j) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (i > j)return 0;
    if (i == j) {
        return segtree[index];
    }
    int mid = i + (j - i) / 2;
    if (k <= mid) {
        return getans(k, i, mid, 2 * index + 1);
    }
    return getans(k, mid + 1, j, 2 * index + 2);
    return 0;
}
int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    for (auto &i : a)cin >> i;
    build(0, 0, n - 1, a);
 
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (x & 1) {
            int u, v, value;
            cin >> u >> v >> value;
            lazyupdate(u - 1, v - 1, value, 0, 0, n - 1);
 
        }
        else {
            int k; cin >> k;
            cout << getans(k-1,0,n-1,0) << " ";
 
        }
    }
}