#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr, int left, int right)
{
    int count = 0;
    int mid = left + (right - left) / 2;
    int lsize = mid - left + 1;
    int rsize = right - mid;
    vector<int> left_array(lsize, 0);
    vector<int> right_array(rsize, 0);
    for(int i = 0;i < lsize;i++)
    {
        left_array[i] = arr[left + i];
    }
    for(int i = 0;i < rsize;i++)
    {
        right_array[i] = arr[mid + i + 1];
    }
    int k = left;
    int i = 0;
    int j = 0;
    while(i < lsize && j < rsize)
    {
        if(left_array[i] <= right_array[j])
        {
            arr[k++] = left_array[i++];
        }
        else
        {
            count += (lsize - i);
            arr[k++] = right_array[j++];
        }
        
    }
    while(i < lsize) arr[k++] = left_array[i++];
    while(j < rsize) arr[k++] = right_array[j++];

    return count;
}
int mergesort(vector<int>& arr, int left, int right)
{
    int count = 0;
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        count += mergesort(arr, left,mid);
        count += mergesort(arr, mid + 1, right);
        count += merge(arr, left, right);
    }
    return count;
}
int inversions(vector<int>& arr)
{
    return mergesort(arr, 0, arr.size() - 1);
}
int main(void)
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int& i : arr) cin>>i;
    cout<<inversions(arr)<<endl;
    return 0;
}