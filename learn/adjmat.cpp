#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    int vertices = 0;
    bool directed = false;
    vector<vector<int>> adj;
    public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adj = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }
    Graph(int vertices, bool flag)
    {
        this->vertices = vertices;
        adj = vector<vector<int>>(vertices, vector<int>(vertices, 0));
        directed = flag;
    }
    void connect(int source, int destination)
    {
        adj[source][destination] = 1;
        if(directed) adj[destination][source] = 1;
    }
    void getInfo()
    {
        for(int i = 0;i < vertices;i++)
        {
            for(int j = 0;j < vertices;j++)
            {
                if(adj[i][j] == 1)
                {
                    cout<<"Edge exists between node :"<<i<<" and node "<<j<<endl;
                }
            }
        }
    }
    vector<int> getNeighbours(int vertice)
    {
        vector<int> neighbors;
        for(int j = 0;j < vertices;j++)
        {
            if(adj[vertice][j] == 1)
            {
                neighbors.push_back(j);
            }
        }
        return neighbors;
    }
    int getvertices()
    {
        return vertices;
    }
};
void breadth(Graph* g)
{
    vector<bool> visited(g->getvertices(), false);
    //vector<int> result;
    queue<int> q;
    q.push(0);
    while(q.empty() != true)
    {
        int v = q.front();
        q.pop();
        visited[v] = true;
        cout<<"Node visited is :"<<v<<endl;
        for(int i : g->getNeighbours(v))
        {
            if(visited[i] == false) q.push(i);
        }
    }
}
int main(void)
{
    int vertices;
    cin>>vertices;
    Graph* g = new Graph(vertices);
    g->connect(0, 1);
    g->connect(0, 2);
    g->connect(0, 3);
    g->connect(2, 4);
    g->connect(4, 1);
    breadth(g);
    return 0;
}