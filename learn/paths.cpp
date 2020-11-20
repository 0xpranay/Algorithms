#include<bits/stdc++.h>
using namespace std;
bool isSafe(int i, int j, int rows, int cols)
{
    cout<<"Checking for "<<i<<" and "<<j;
    if(i < rows && j < cols && i >= 0 && j >= 0)
    {
        cout<<"Check pass\n";
        return true;
    }
    else return false;
}
int paths(int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& grid)
{
    if(!isSafe(i, j, dp.size(), dp[0].size()))
    {
        cout<<"NOT SAFE...returning\n";
        return 0;
    }
    else if(grid[i][j] == false) return 0;
    else if(dp[i][j] != -1) return dp[i][j];
    else
    {
        dp[i][j] = paths(i - 1, j, dp, grid) + paths(i, j-1, dp, grid);
    }
    return dp[i][j];
}
int main(void)
{
    int rows = 8;
    int cols = 16;
    vector<vector<bool>> grid(8, vector<bool>(16, true));
    vector<vector<int>> dp(8, vector<int>(16, -1));
    cout<<"Grid is\n";
    for(vector<bool> v:grid)
    {
        for(bool k:v) cout<<k<<" ";
        cout<<endl;
    }
    cout<<"DP array is\n";
    for(vector<int> v:dp)
    {
        for(int k:v) cout<<k<<" ";
        cout<<endl;
    }
    dp[0][0] = 1;
    grid[0][8] = false;
    grid[6][8] = false;
    grid[7][8] = false;
    grid[0][12] = false;
    grid[1][12] = false;
    grid[7][12] = false;
    cout<<paths(7, 15, dp, grid)<<endl;
    return 0;
}