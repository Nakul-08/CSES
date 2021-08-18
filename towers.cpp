#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int v = upper_bound(a.begin(), a.end(), x) - a.begin();
        if (v < a.size()) {
            a[v] = x;//if there exits a large tower which can be replace by a smaller tower.
            //update it
        }
        else {
            a.push_back(x);
            //add new tower
        }
    }
    cout<<a.size();
}


