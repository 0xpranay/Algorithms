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
bool safe(int i, int j, int row, int col)
{
    return (i >= 0 && i < row) && (j >= 0 && j < col);
}
void fix(vector<vector<ll>>& arr, int i, int j, int n, int m)
{
    ll left = -1, right = -1, up = -1, down = -1;
    if(safe(i, j - 1,n,m)) left = arr[i][j - 1];
    if(safe(i, j + 1,n,m)) right = arr[i][j + 1];
    if(safe(i - 1, j,n,m)) up = arr[i - 1][j];
    if(safe(i + 1, j,n,m)) down = arr[i + 1][j];

    ll val = arr[i][j];
    if(left != val && right != val && up != val && down != val) return;
    ll temp = val + 1;
    if(left != temp && right != temp && up != temp && down != temp)
    {
        arr[i][j] = temp;
        return;
    }
}
int main()
{
    cases
    {
        ll n = 0;
        ll m = 0;
        cin>>n>>m;
        vector<vector<ll>> arr(n, vector<ll>(m, 0));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                fix(arr, i, j, n, m);
            }
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
