#include<bits/stdc++.h>
using namespace std;
int tile(int n)
{
    return n == 1 ? 1 : n == 2 ? 2 : tile(n - 1) + tile(n - 2);
}
void duration(time_t start, time_t end)
{
    cout<<"------------------------------------------------------\n";
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    cout << " sec " << endl;
    cout<<"------------------------------------------------------\n";
    return;
}
int dynamic(int t, vector<int>& arr)
{
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3;i < arr.size();i++) arr[i] = arr[i - 1]+ arr[i - 2];
    return arr[t];
}
int main(void)
{
    int t;
    cin>>t;
    time_t start,end;
    time(&start);
    cout<<tile(t)<<endl;
    time(&end);
    duration(start, end);
    time(&start);
    vector<int> arr(t + 1, -1);
    cout<<dynamic(t, arr)<<endl;
    time(&end);
    duration(start, end);
    return 0;
}