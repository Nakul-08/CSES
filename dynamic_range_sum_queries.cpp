#include<bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>segtree((1 << 19), 0);
void build(vector<int>&a, int index, int i, int j) {
    if(i>j)return;
    if (i == j) {
        segtree[index] = a[i];
        return;
    }
    int mid = i + (j - i) / 2;;
    build(a, 2 * index + 1, i, mid);
    build(a, 2 * index + 2, mid + 1, j);
    segtree[index] = segtree[(2 * index) + 1] + segtree[(2 * index) + 2];
}
void update(vector<int>&a, int index, int i, int j, int k, int value) {
    if (k<i||k>j)return;
        if (i == j) {
            segtree[index] = value;
            return;
        }
    int mid = i + (j - i) / 2;
    update(a, 2 * index + 1, i, mid, k, value);
    update(a, 2 * index + 2, mid + 1, j, k, value);
    segtree[index] = segtree[(2 * index) + 1] + segtree[(2 * index) + 2];
}
int get_ans(int index, int x, int  y, int l, int r) {
    if (y < l || x > r)return 0;
    if (x >= l && y <= r)return segtree[index];
    int mid = x + (y - x) / 2;
    return (get_ans((2 * index) + 1, x, mid, l, r) + get_ans((2 * index + 2), mid + 1, y, l, r));
}
int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a, 0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            update(a, 0, 0, n - 1, y - 1, z);
        }
        else {
            cout << get_ans(0, 0, n - 1, y - 1, z - 1) << " ";
        }
    }

}
