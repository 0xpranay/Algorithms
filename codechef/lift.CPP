#include<bits/stdc++.h>
#define LL long long int
#define endl "\n"
using namespace std;
int main(void)
{
    LL d, w, s;
    cin>>d>>w>>s;
    LL target = 300 - (w * d);
    LL sum = 0;
    vector<LL> v(d, 0);
    for(int i = 0 ;i < d;i++) cin>>v[i];
    for(int i :v)
    {
        sum += (s - (s * (i - 1) * 0.02));
    }
    if(sum >= target) cout<<"YES";
    else cout<<"NO";
    return 0;
}