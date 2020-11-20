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
string solve(string str, int n)
{
    if(str.size() <= 1) return "NO";
    for(int j = str.size() - 1;j >= 0;j--)
    {
        string a = str.substr(0,j);
        string b = str.substr(j, str.length() - j);
        //cout<<"A and B are "<<a<<" "<<b<<endl;
        if(a.find(b) != string::npos) return "YES";
    }
    //cout<<endl<<endl<<endl;
    return "NO";
}
int main()
{
    cases
    {
        int n;
        string str;
        cin>>n>>str;
        cout<<solve(str, n)<<endl;
    }
    return 0;
}
