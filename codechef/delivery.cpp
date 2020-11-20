#include<bits/stdc++.h>
#define LL long long int
#define endl "\n"
using namespace std;
LL solve(vector<LL> a, vector<LL> b, LL n, LL x, LL y)
{
    //cout<<"Input parameters are "<<n<<" "<<x<<" "<<y<<endl;
    LL tip = 0;
    LL i = 0;
    LL j = 0;
    LL andy = x;
    LL bob = y;
    LL q = 0, w = 0;
    while(n--)
    {
        if(andy > 0 && bob > 0)
        {
            if(max(a[i], b[j]) == a[i])
            {
                andy--;
            }
            else bob--;
            tip += max(a[i], b[j]);
        }
        else if (andy > 0)
        {
            tip += a[i];
            andy--;
        }
        else if(bob > 0)
        {
            tip += b[j];
            bob--;
        }
        i++;
        j++;
    }
    return tip;
}
int main(void)
{
    LL n, x, y;
    cin>>n>>x>>y;
    vector<LL> a(n, 0);
    vector<LL> b(n, 0);
    for(int i = 0 ;i < n;i++) cin>>a[i];
    for(int i = 0 ;i < n;i++) cin>>b[i];
    cout<<solve(a, b, n, x, y);
    return 0;
}