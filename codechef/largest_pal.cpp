#include<bits/stdc++.h>
#define LL long long int
#define endl "\n"
using namespace std;
bool isPalindrome(string n) { 
  for (int i = 0; i < n.size() / 2; i++) 
    if (n[i] != n[n.size() - 1 - i]) 
      return false; 
  return true; 
} 
  
//N to S
string convertNumIntoString(LL num) { 
  
  // base case: 
  if (num == 0) 
    return "0"; 
  
  string Snum = ""; 
  while (num > 0) { 
    Snum += (num % 10 - '0'); 
    num /= 10; 
  } 
  return Snum; 
}
int main(void)
{
    LL t = 0;
    cin>>t;
    LL ref = t;
    while(t > 0)
    {
        if(isPalindrome(convertNumIntoString(t)) == true)
        {
            cout<<t<<" "<<ref - t;;
            return 0;
        }
        t--;
    }
}