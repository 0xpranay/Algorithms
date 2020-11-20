#include<bits/stdc++.h>
#define cases long long t;cin>>t;while(t--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long int
#define MOD 1000000007
#define endl "\n"
#define INF 1000000000
using namespace std;
int main()
{
    cases
    {
        int l, r;
        cin>>l>>r;
        if(l == 1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = false;
        for(int i = 3;i <= 2*r;i++)
        {
            if(l % i >= i / 2 && r % i >= i / 2)
            {
                flag = true;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
