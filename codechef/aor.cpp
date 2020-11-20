#include<bits/stdc++.h>
#define cases long long t;cin>>t;while(t--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long
#define MOD 1000000007
#define INF 1000000000
#define endl "\n"
using namespace std;
int main(void)
{
    cases
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i = 0;i < n;i++)
        {
            cin>>arr[i];
        }
        ll num1 = 0;
        ll num2 = 0;
        for(ll j : arr)
        {
            num1 = (num1 | j);
            num2 = (num2 + j);
        }
        cout<<(num1 | num2)<<endl;
    }
    return 0;
}
