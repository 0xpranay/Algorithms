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
void solve(ll windows)
{
    if(windows < 15)
    {
        if(windows % 3 == 0) cout<<windows/3<<" "<<0<<" "<<0<<endl;
        else if(windows % 5==0) cout<<0<<" "<<windows/5<<" "<<0<<endl;
        else if(windows % 7==0) cout<<0<<" "<<0<<" "<<windows/7<<endl;
        else
        {
            if(windows == 1 || windows == 2 || windows == 4) cout<<-1<<endl;
            else if(windows == 8) cout<<1<<" "<<1<<" "<<0<<endl;
            else if(windows == 11) cout<<-1<<endl;
            else if(windows == 13) cout<<-1<<endl;
        }
        return;
    }
    else
    {
        ll k = windows / 15;
        ll three = 0;
        ll fives = 0;
        ll sevens = 0;
        three = k;
        fives = k;
        sevens = k;
        int rem = (windows % 15);
        if(rem % 3 == 0 || rem % 5 == 0 || rem % 7 == 0)
        {
            rem % 3 == 0 ? three += (rem/3) : three += 0;
            rem % 5 == 0 ? fives += (rem / 5) : fives += 0;
            rem % 7 == 0 ? sevens += (rem / 7) : sevens += 0;
        }
        else
        {
            if(rem == 8)
            {
                three += 1;
                fives += 1;
            }
            else if(rem == 4)
            {
                three -= 1;
                sevens += 1;
            }
            else if(rem == 2)
            {
                three -= 1;
                fives += 1;
            }
            else if(rem == 1)
            {
                fives -= 1;
                three += 2;
            }
            else if(rem == 11)
            {
                sevens -= 1;
                three += 6;
            }
            else if(rem == 13)
            {
                fives -= 1;
                three += 6;
            }
        }
        
        cout<<three<<" "<<fives<<" "<<sevens<<endl;
    }
}
int main()
{
    ll windows = 0;
    foi(1,1001) solve(i);
    return 0;
}
