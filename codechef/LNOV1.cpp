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
ll solve(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    ll x = 0;
    ll y = 0;
    ll i = arr.size() - 1;
    ll time = 0;
    ll m = 0;
    //cout<<"-------Loop starting---------\n";
    while(i >= 0)
    {
        //cout<<"Burner 1 has "<<x<<" and burner 2 has "<<y<<endl; 
        //cout<<"I value now is "<<i<<endl;       
        if(x == 0)
        {
            //cout<<"Filling burner 1 now..\n";
            //cout<<"I value at X is "<<i<<endl;
            if(i >= 0) x = arr[i--];
            //cout<<"I value after X updation is "<<i<<endl;
        }
        if(y == 0)
        {
            //cout<<"Filling burner 2 now..\n";
            //cout<<"I value at Y is "<<i<<endl;
            if(i >= 0) y = arr[i--];
            //cout<<"I value after Y updation is "<<i<<endl;
        }
        //cout<<"Burner 1 is now "<<x<<" burner 2 is now "<<y<<endl;
        time += min(x, y);
        //cout<<"Min is "<<min(x, y)<<" and time elapsed is "<<time<<endl;
        m = min(x, y);
        x -= m;
        y -= m;
        //cout<<"After time has elapsed...burner 1 is "<<x<<" and burner 2 is..."<<y<<endl;
    }
    //cout<<"-------Loop has ended---------\n";
    return time + max(x, y);
}
int main()
{
    cases
    {
        ll n;
        cin>>n;
        vector<int> arr(n, 0);
        for(int& i : arr) cin>>i;
        cout<<solve(arr)<<endl;
    }
    return 0;
}
