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
    foi(14,1001)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int res = (3*a)+(5*b)+(7*c);
        if(i != res) cout<<i<<" FALSE "<<endl;
    }
    cout<<"DONE\n";
    return 0;
}
