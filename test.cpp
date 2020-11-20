#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,tc=0;cin>>n;
  set<pair<int,int>> s;
  map<int,int> cost;
  for (int i = 0; i < n; i++) {
    int a,b,c;cin>>a>>b>>c;
    s.insert(make_pair(a,b));
    cost[a]=c;
    tc+=c;
  }
  int ans=0,count=0;
  for (int i = 0; i < n; i++) {
    int sum=0,l=0,sub_count=0;
    for (auto p:s) {
      if (p.first>=l) {
        sum+=cost[p.first];
        sub_count++;
        l=p.second;
      }
    }
    if (sum>=ans) {
      ans=max(ans,sum);
      count=sub_count;
    }
    s.erase(s.begin());
  }
  cout<<n-count<<"\n"<<tc-ans;
}
