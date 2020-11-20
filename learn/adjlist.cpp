#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    int vertices;
    bool directed = false;
    vector<vector<int>> adjlist;
    public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adjlist = vector<vector<int>>(vertices, vector<int>());
    }
    Graph(int vertices, bool directed)
    {
        this->vertices = vertices;
        this->directed = directed;
        adjlist = vector<vector<int>>(vertices, vector<int>());
    }
    void connect(int source, int destination)
    {
        adjlist[source].push_back(destination);
        if(directed) adjlist[destination].push_back(source);
    }
    bool edgeExists(int source, int destination)
    {
        for(auto i : adjlist[source])
        {
            if(i == destination) return true;
        }
        return false;
    }
    void getInfo()
    {
        for(int i = 0;i < vertices;i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if(edgeExists(i, j)) cout<<"Edge exists between "<<i<<" and "<<j<<endl;
            }
            
        }
        return;
    }
    vector<int> getNeighbours(int source)
    {
        vector<int> res;
        for(int i : adjlist[source]) res.push_back(i);
        return res;
    }
    int getvertices()
    {
        return vertices;
    }
};
void dfsUtil(Graph* g, int source, vector<bool>& visited)
{
    cout<<"Node visited is :"<<source<<endl;
    visited[source] = true;
    for(int i : g->getNeighbours(source))
    {
        if(visited[i] == false)
        {
            dfsUtil(g, i, visited);
        }
    }
}
void dfs(Graph* g, int source)
{
    vector<bool> visited(g->getvertices(), false);
    stack<int> s;
    s.push(source);
    visited[source] = true;
    while (s.empty() == false)
    {
        int v = s.top();
        cout<<"Node visited is :"<<v<<endl;
        s.pop();
        for(int i : g->getNeighbours(v))
        {
            if(visited[i] == false)
            {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    
}
int main(void)
{
    int vertices;
    cin>>vertices;
    Graph* g = new Graph(vertices, true);
    g->connect(0, 1);
    g->connect(0, 2);
    g->connect(0, 3);
    g->connect(2, 4);
    g->connect(4, 1);
    g->getInfo();
    dfs(g,0);
    return 0;
}