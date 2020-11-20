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
void printarr(int arr[], int n)
{
    foi(0, n) cout<<arr[i]<<" ";
    cout<<endl;
}
void duration(time_t start, time_t end)
{
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    cout << " sec " << endl;
    return;
}
ll merge(int arr[], int left, int right)
{
    ll count = 0;
    int mid = left + (right - left) / 2;
    int lsize = mid - left  + 1;
    int rsize = right - mid;
    int leftarr[lsize];
    int rightarr[rsize];
    for(int i = 0 ;i < lsize;i++) leftarr[i] = arr[left + i];
    for(int i = 0;i <  rsize;i++) rightarr[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = left;
    while(i < lsize && j < rsize)
    {
        if(leftarr[i] <= rightarr[j]) arr[k++] = leftarr[i++];
        else
        {
            arr[k++] = rightarr[j++];
            count = count + (lsize - i);
        }
    }
    while(i < lsize) arr[k++] = leftarr[i++];
    while(j < rsize) arr[k++] = rightarr[j++];
    return count;
}
ll mergesort(int arr[], int left, int right)
{
    ll count = 0;
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        count += mergesort(arr, left, mid);
        count += mergesort(arr, mid + 1, right);
        count += merge(arr, left ,right);
    }
    return count;
}
int main()
{
    time_t start, end;
    time(&start);
    cases
    {
        int t;
        cin>>t;
        int arr[t];
        foi(0,t) cin>>arr[i];
        cout<<mergesort(arr, 0, t - 1)<<endl;
    }
    time(&end);
    duration(start, end);
}
