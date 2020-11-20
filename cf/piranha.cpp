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
        int n;
        cin>>n;
        vector<int> arr(n);
        int mx = 0;
        for(int i = 0;i < n;i++)
        {
            cin>>arr[i];
            mx = max(mx, arr[i]);
        }
        int idx = -1;
        for(int i = 0;i < n;i++)
        {
            if(arr[i] != mx) continue;
            else if(i > 0 && arr[i - 1] != mx) idx = i + 1;
            else if(i < n - 1 && arr[i + 1] != mx) idx = i + 1;
        }
        cout<<idx<<endl;
    }
    return 0;
}
