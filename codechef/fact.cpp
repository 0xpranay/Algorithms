#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int main(void)
{
    int cases = 15;
    int ans = 0;
    while(cases--)
    {
        int num = 0;
        cin>>num;
        ans = (ans | num);
    }
    cout<<ans;
    return 0;
}