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
void duration(time_t start, time_t end)
{
    cout<<"------------------------------------------------------\n";
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    cout << " sec " << endl;
    cout<<"------------------------------------------------------\n";
    return;
}
void printarr(int arr[], int n)
{
    foi(0,n) cout<<arr[i]<<" ";
    cout<<endl;
    return;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j < high;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}
void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1,high);
    }
}
int main()
{
    time_t start, end;
    time(&start);
    cases
    {
        int t = 0;
        int k = 0;
        cin>>t>>k;
        int arr[t];
        foi(0, t) cin>>arr[i];
        quicksort(arr, 0, t - 1);
        int diff = INT_MAX;
        foi(0, t - k)
        {
            diff = min(diff, (arr[i + k - 1] - arr[i]) );
        }
        cout<<diff<<"\n";
    }
    time(&end);
    duration(start, end);
    return 0;
}
