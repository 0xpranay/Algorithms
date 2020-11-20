#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    int vertices;
    bool un_directed = true;
    vector<vector<int>> adjList;
    vector<int> distances;
    public:
    Graph(int vertices,bool un_directed)
    {
        this->vertices = vertices;
        this->un_directed = un_directed;
        adjList = vector<vector<int>>(vertices, vector<int>());
        distances = vector<int>(vertices, INT_MAX);
        setSource(0);
    }
    int getVertices()
    {
        return vertices;
    }
    void connect(int source, int destination)
    {
        cout<<"Connecting "<<source<<" and "<<destination<<endl;
        adjList[source].push_back(destination);
        if(un_directed) adjList[destination].push_back(source);
    }
    vector<int> getNeighbors(int source)
    {
        vector<int> result;
        for(int i:adjList[source])
        {
            result.push_back(i);
        }
        return result;
    }
    void setSource(int source)
    {
        distances[source] = 0;
    }
    void getDistances()
    {
        for(int i : distances) cout<<i<<" ";
        cout<<endl;
    }
    int getDistances(int n)
    {
        return distances[n];
    }
    void setDistance(int index, int val)
    {
        distances[index] = val;
    }
};
void breadth(Graph g)
{
    cout<<"Breath fxn running\n";
    int source = 0;
    queue<int> q;
    vector<int> visited(g.getVertices(), false);
    q.push(source);
    visited[source] = true;
    while(q.empty() == false)
    {
        int node = q.front();
        q.pop();
        cout<<"Value popped is "<<node<<endl;
        for(int i : g.getNeighbors(node))
        {
            if(visited[i] == false)
            {
                g.setDistance(i, min(g.getDistances(i), g.getDistances(node) + 1));
                cout<<"Pushing "<<i<<endl;
                visited[i] = true;
                q.push(i);
            }
            else g.setDistance(i, min(g.getDistances(i), g.getDistances(node) + 1));
        }
    }
}
int main(void)
{
    int cases = 0;
    cin>>cases;
    while (cases--)
    {
        int nodes, edges;
        cin>>nodes>>edges;
        Graph g = Graph(nodes, true);
        while(edges--)
        {
            int source, destination;
            cin>>source>>destination;
            g.connect(source, destination);
        }
        breadth(g);
        g.getDistances();
    }
    return 0;
}