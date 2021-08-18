#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    set<int>st;
    multiset<int>dist;
    st.insert(0);
    st.insert(n);
    dist.insert(n);
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        auto it1=st.upper_bound(x);
        auto it2=it1;
        --it2;
        //x will be inserted between it1 and it2 so this distance will be lost
        // and new distance will be form which are x-it2 and it1-x
        //for our ans we simple take second last value in the multiset as the last value will be n itself.
        dist.erase(dist.find(*it1-*it2));
        dist.insert(x-*it2);
        dist.insert(*it1-x);
        st.insert(x);
        auto ans=dist.end();
        --ans;
        cout<<*ans<<" ";

    }

}

