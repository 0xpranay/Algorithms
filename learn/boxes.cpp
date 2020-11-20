#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    int cases = 0;
    cases = 1;
    while(cases--)
    {
        ll n = 0;
        ll h = 0;
        ll x = 1;
        bool box = false;
        cin>>n>>h;
        vector<ll> arr(n, 0);
        for(ll& i : arr) cin>>i;
        int i = 0;
        while(x != 0)
        {
            cin>>x;
            if(x == 1) i = i - 1 < 0 ? i : i - 1;
            if(x == 2) i = (i == n - 1) ? i : i + 1;
            if(x == 3)
            {
                if(arr[i] > 0 && !box)
                {
                    arr[i]--;
                    box = true;
                }
            }
            if(x == 4)
            {
                if(box && arr[i] < h)
                {
                    arr[i]++;
                    box = false;
                }
            }
            
        }
        for(auto i : arr) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}