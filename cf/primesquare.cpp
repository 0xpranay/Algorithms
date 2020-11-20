#include <bits/stdc++.h> 
using namespace std; 
void printarr(vector<vector<int>> v)
{
    for(vector<int> i : v)
    {
        for(int j : i) cout<<j<<" ";
        cout<<endl;
    }
}
// function check whether a number 
// is prime or not 
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
// Function to print primes 
vector<int> printPrime(int n) 
{ 
    vector<int> m;
    for (int i = 2; i <= n; i++) { 
        if (isPrime(i)) 
            m.push_back(i); 
    } 
    return m;
} 
// Driver Code 
bool func(vector<int> m, int val)
{
    for(int i : m)
    {
        if(i == val) return true;
    }
    return false;
}
vector<vector<int>> primesquare(int n, vector<int> m)
{
    vector<vector<int>> result(n, vector<int>(n, 1));
    int sum = n;
    if(isPrime(n) == true) return result;
    else if(isPrime(n - 1) == true)
    {
        int i = 0;
        int j = n - 1;
        while(i < n && j >= 0)
        {
            result[i][j] = 0;
            i++;
            j--;
        }
    }
    else
    {
        for(int i = 1;i < 100;i++)
        {
            if(isPrime(sum + i - 1) == true && func(m, i) == false)
            {
                //cout<<"Condition satisfied for "<<i<<endl;
                int row = 0;
                int col = n - 1;
                while(row < n && col >= 0)
                {
                    result[row][col] = i;
                    row++;
                    col--;
                }
                break;
            }
        }
    }
    return result;
    
}
int main() 
{ 
    int n = 100; 
    vector<int> primes = printPrime(n);
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        vector<vector<int>> result = primesquare(n, primes);
        printarr(result);
    }
}