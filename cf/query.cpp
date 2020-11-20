#include<bits/stdc++.h>
#define cases long long t;cin>>t;while(t--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long
#define MOD 1000000007
#define INF 1000000000
using namespace std;
int main()
{
    cases
    {
        ll n,q;
        cin>>n>>q;
        vector<ll> arr(n, 0);
        vector<ll> lcs(n, 0);
        for(ll i = 0;i < n;i++) cin>>arr[i];
        lcs[0] = 1;
        for(ll i = 1;i < n;i++)
        {
            if(arr[i] == arr[i - 1])
            {
                lcs[i] = 1;
            }
            else lcs[i] = lcs[i - 1] + 1;
        }
        while(q--)
        {
            ll index, num;
            ll val = INT_MIN;
            cin>>index>>num;
            if(n == 1)
            {
                cout<<1<<endl;
                continue;
            }
            arr[index - 1] = num;
            for(ll i = 1;i < n;i++)
            {
                if(arr[i] == arr[i - 1])
                {
                    lcs[i] = 1;
                }
                else
                {
                    lcs[i] = lcs[i - 1] + 1;
                }
                val = max(val, lcs[i]);
            }
            cout<<val<<endl;
        }
    }
    return 0;
}
