#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int main(void)
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n = s.length();
        string left  = s.substr(0, n/2);
        string right = (n % 2 == 0) ? s.substr(n/2, n/2) : s.substr(n/2 + 1, n/2);
        if(left == right) cout<<"YES"<<"\n";
        else cout<<"NO\n";
    }
    return 0;
}