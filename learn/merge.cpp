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
void printarr(int a[], int n)
{
    foi(0, n) cout<<a[i]<<" ";
    cout<<endl;
    return;
}
void merge(int arr[], int left, int right)
{
    int mid = left + (right - left) / 2;
    int lsize = mid - left + 1;
    int rsize = right - mid;
    int leftarr[lsize];
    int rightarr[rsize];
    foi(0, lsize)
    {
        leftarr[i] = arr[left + i];
    }
    foi(0, rsize)
    {
        rightarr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, pos = left; 
    while (i < lsize && j < rsize)
    {
        if (leftarr[i] <= rightarr[j]) 
            arr[pos++] = leftarr[i++];      
        else 
            arr[pos++] = rightarr[j++];      
    }
 
    // Add the remaining elements in either of the two arrays.
    while (i < lsize)
        arr[pos++] = leftarr[i++];
    while (j < rsize)
        arr[pos++] = rightarr[j++];
}
void mergesort(int arr[], int left, int right)
{
    if(left == right) return;
    int mid = left + (right - left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr,mid+1, right);
    merge(arr, left, right);
}
int main()
{
    int a[] = {10, 20, 5, 8, 7, 2, 15, 12};
    printarr(a, 8);
    mergesort(a, 0, 7);
    printarr(a, 8);
    return 0;
}
