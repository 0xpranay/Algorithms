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
int digits(int n)
{
    //cout<<"Entered num is"<<n<<endl;
    int count = 0;
    while(n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
int main()
{
    vector<int> arr = {1,11,111,1111,2,22,222,2222,3,33,333,3333,4,44,444,4444,5,55,555,5555,6,66,666,6666,7,77,777,7777,8,88,888,8888,9,99,999,9999};
    cases
    {
        int num;
        cin>>num;
        int count = 0;
        foi(0,arr.size())
        {
            if(arr[i] == num)
            {
                break;
            }
            else
            {
                count += digits(arr[i]);
            }
            
        }
        count += digits(num);
        cout<<count<<endl;
    }
    return 0;
}
