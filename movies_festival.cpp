#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&a,pair<int,int>&b){
    return b.second>a.second;
}
int main() {
    int n, x;
    cin >> n;
    vector<pair<int, int>>a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),comp);
    vector<pair<int,int>>ans;
    for(int i=0;i<n;i++){
        if(i==0){
            ans.push_back(a[i]);
        }
        else{
            if(ans.back().second<=a[i].first){
                ans.push_back(a[i]);
            }
        }
    }
  // for(int i=0;i<n;i++){
  //   cout<<a[i].first<<" "<<a[i].second<<endl;
  // }
    cout<<ans.size();
}

