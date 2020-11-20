#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int main(void)
{
    LL t,n,speed,temp,count = 0;
    cin>>t;
    while (t--)
    {
        cin>>n;
        n -= 1;
        cin>>speed;
        count++;
        while(n--)
        {
            cin>>temp;
            if(temp <= speed)
            {
                count++;
                speed = temp;
            }
        }
        cout<<count<<"\n";
        count = 0;
    }

    
    return 0;
}