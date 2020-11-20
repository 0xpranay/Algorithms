#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    /*for(auto i : dp)
    {
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }*/
    for(int i = 1;i <= s1.size();i++)
    {
        for(int j = 1;j <= s2.size();j++)
        {
            //cout<<"Query for "<<i<<" and "<<j<<endl;
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s1.size()][s2.length()];
}
int main(void)
{
    string s1, s2;
    //cin>>s1>>s2;
    s1 = "CCJFCFIGEAAAEBHHDIKAGIHCDGCAGIAKHFIKJCEJDBEBKDCGBEDFK";
    s2 =  "HCGEIDJCHHDDKECBBEFDHCCHKGHCFKGIJJGHIIFFKADGFBAECABDAJIGDFJBEDKIICAKIKKEIHCEHH";
    cout<<lcs(s1, s2)<<endl;
}