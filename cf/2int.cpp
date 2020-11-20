#include<bits/stdc++.h>
#define LL long long int
using namespace std;
LL solve(LL a, LL b)
{
    int count = 0;
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    LL diff = b - a;
    int i = 0;
    //cout<<"Diff is "<<diff<<"\n";
    while(diff > 0)
    {
        if(diff >= arr[i])
        {
            //cout<<"Used "<<arr[i]<<"\n";
            diff -= arr[i];
            count++;
        }
        else i++;
    }
    return count;
}
int main(void)
{
    int t,a,b;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        if(a > b) swap(a,b);
        cout<<solve(a ,b)<<"\n";
    }
    return 0;
}