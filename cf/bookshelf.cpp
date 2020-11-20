#include<bits/stdc++.h>
#define cases long long t;cin>>t;while(t--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long int
#define MOD 1000000007
#define INF 1000000000
using namespace std;
void printarr(vector<int> arr)
{
    foi(0,arr.size()) cout<<arr[i]<<" ";
    cout<<endl;
    return;
}
int solve(int arr[], int n)
{
    if(n <= 2) return 0;
    int i;
    int j;
    int start = 0;
    int end = n;
    if(arr[0] == 0)
    {
        for(i = 0;i < n;i++)
        {
            if(arr[i] == 0 && arr[i + 1] == 1)
            {
                break;
            }
        }
        start = i + 1;
    }
    if(arr[n - 1] == 0)
    {
        for(j = n - 1;j >= 0;j--)
        {
            if(arr[j] == 0 && arr[j - 1] == 1)
            {
                break;
            }
        }
        end = j;
    }
    
    
    //cout<<"Start is "<<start<<" and end is "<<end<<"\n";
    bool val[n];
    val[0] = false;
    foi(start,end)
    {
        if(arr[i] == 1)
        {
            val[i] = false;
        }
        else if(val[i - 1] == true || arr[i - 1] == 1)
        {
            val[i] = true;
        }
    }
    int count = 0;
    foi(start, end)
    {
        if(val[i] == true) count++;
    }
    return count;
}
int main()
{
    cases
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
        {
            int a = 0;
            cin>>a;
            arr[i] = a;
        }
        cout<<solve(arr, n)<<endl;
    }
    return 0;
}
