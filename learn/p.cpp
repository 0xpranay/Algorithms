#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    unordered_map<int, int> m;
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++) cin>>arr[i];
    for(int i = 0;i < n;i++) m[arr[i]]++;
    for(int i = 0;i < n;i++) arr[i] = (n - m[arr[i]]);
    for(int i = 0;i < n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}