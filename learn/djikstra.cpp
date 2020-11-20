#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
class Graph
{
    private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;
    int un_directed = true;
    public:
    Graph(int vertices, bool un_directed)
    {
        this->vertices = vertices;
        adjList = vector<vector<pair<int, int>>>(vertices,vector<pair<int,int>>());
        this->un_directed = un_directed;
    }
    void connect(int source, int destination, int weight)
    {
        cout<<"Connecting "<<source<<" with destination "<<destination<<" and weight "<<weight<<endl;
        adjList[source].push_back({destination, weight});
        if(un_directed) adjList[destination].push_back({source, weight});
        cout<<"Connected\n";
    }
    vector<pair<int, int>> getNeighbors(int source)
    {
        return adjList[source];
    }
    int getVertices()
    {
        return vertices;
    }
};
void djikstra(Graph* g,int source)
{
    cout<<"Djikstra running\n";
    int vertices = g->getVertices();
    cout<<"Number of vertices are "<<vertices<<endl;
    vector<int> distances(vertices, INT_MAX);
    vector<int> prev(vertices, source);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//Stores distance from source and node
    distances[source] = 0;
    pq.push({0, source});
    cout<<"Distance of all vertices from source "<<source<<" to :  \n";
    while (pq.empty() == false)
    {
        pair<int, int> current = pq.top();//has format {distance form source, node}
        pq.pop();
        for(pair<int, int> i: g->getNeighbors(current.second))
        {
            //i has format {node, weight of edge}
            if(distances[i.first] > distances[current.second] + i.second)
            {
                distances[i.first] = distances[current.second] + i.second;
                prev[i.first] = current.second;
                pq.push({distances[i.first], i.first});
            }
        }
    }
    for(int i = 0;i < distances.size();i++)
    {
        cout<<i<<" : "<<distances[i]<<" and prev is "<<prev[i]<<endl;
    }
}
int main(void)
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int vertices;
        int edges;
        int weights;
        cin>>vertices;
        cin>>edges;
        Graph* g = new Graph(vertices, true);
        while(edges--)
        {
            int source,destination,weight;
            cin>>source>>destination>>weight;
            g->connect(source, destination, weight);
        }
        djikstra(g, 0);
    }
    return 0;
}