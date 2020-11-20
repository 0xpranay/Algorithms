#include<bits/stdc++.h>
using namespace std;
class Item
{
    public:
        int val, pos, source;
        Item(int val, int pos, int source)
        {
            this->val = val;
            this->pos = pos;
            this->source = source;
        }
};
class compare
{
    public:
        bool operator()(Item const &a, Item const &b)
        {
            return a.val > b.val;
        }
};
vector<int> ksort(vector<vector<int>> v)
{
    //cout<<"Supplied array is\n";
    vector<int> answer;
    priority_queue<Item, vector<Item>, compare> pq;
    //Inserting first k elements
    for(int i = 0;i < v.size();i++)
    {
        Item a = Item(v[i][0], 0, i);
        pq.push(a);
        //cout<<"Inserted "<<a.val<<"\n";
    }
    while(!pq.empty())
    {
        Item a = pq.top();
        //cout<<"Min element is "<<a.val<<"\n";
        pq.pop();
        answer.push_back(a.val);
        if( (a.pos + 1) < v[a.source].size())
        {
            Item b = Item(v[a.source][a.pos + 1], a.pos + 1, a.source);
            pq.push(b);
            //cout<<"Item pushed is "<<b.val<<"\n";
        }
    }
    return answer;
}
int main(void)
{
    freopen("output.txt", "w", stdout);
    int t, n, k, num;
    cin>>t;
    //cout<<"Test cases are "<<t<<"\n";
    while(t--)
    {
        cin>>k;
        //cout<<"Value of K is "<<k<<" \n";
        vector<vector<int>> v(k, vector<int>());
        vector<int> answer;
        for(int i = 0;i < k;i++)
        {
            cin>>n;
            //cout<<"Array "<<(i + 1)<<" size is "<<n<<"\n";
            for(int j =0;j < n;j++)
            {
                cin>>num;
                v[i].push_back(num);
            }
        }
        answer = ksort(v);
        for(int i : answer) cout<<i<<" ";
        cout<<endl;
    }
}