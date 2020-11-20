#include<bits/stdc++.h>
using namespace std;
string solve(vector<string> v)
{
    string s1, s2;
    unordered_map<char, int> m;
    for(string c : v) s1 += c;
    for(char c: s1) m[c]++;
    for(int i = 0;i < s1.size() - 1;i++)
    {
        if(s1[i + 1] - s1[i] == 1) s2 += s1[i];
        else if(s1[i + 1] - s1[i] > 1)
        {
            int diff = s1[i + 1] - s1[i];
            while(diff--)
            {
                char c = s2[s2.size() - 1]++;
                if(m[c] == 0) s2 += c;
            }
        }
        
    }
    return s2;
}
int main(void)
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        vector<string> v;
        int n;
        cin>>n;
        for(int i = 0;i < n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        cout<<solve(v);
    }
}