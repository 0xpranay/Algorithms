#include<bits/stdc++.h>
#define LL long long int
#define endl "\n"
using namespace std;
int main(void)
{
    LL t;
    LL a, b, n, sum, digit;
    cin>>t;
    while (t--)
    {
        cin>>n>>a>>b;
        sum = a + b;
        n = n - 2;
        while(n--)
        {
            digit = sum % 10;
            sum += digit;
        }
        if(sum % 3 == 0) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    
    return 0;
}