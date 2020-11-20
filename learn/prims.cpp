#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    int vertices;
    bool un_directed = true;
    vector<vector<pair<int, int>>> adjList;
    public:
    Graph(int vertices, bool un_directed)
    {
        this->vertices = vertices;
        this->un_directed = un_directed;
        adjList = vector<vector<pair<int, int>>>(vertices, vector<pair<int, int>>());
    }
    void connect(int source , int destination, int weight)
    {
        adjList[source].push_back({destination, weight});
        if(un_directed == true) adjList[destination].push_back({source,weight});
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
vector<pair<int, int>> Prim(Graph* g)
{
    vector<bool> visited(g->getVertices(), false);
    vector<pair<int, int>> mst;
    int cost = 0;
    //Storing heap in the form of weight from visited node, {node value, prev node value}
    priority_queue<pair<int, pair<int, int>>, vector< pair< int, pair<int, int>>>, greater<pair < int, pair<int, int>> >> pq;
    for(auto i : g->getNeighbors(0))
    {
        pq.push({i.second, {i.first, 0}});
    }
    visited[0] = true;
    while(pq.empty() == false)
    {
        pair<int, pair<int, int>> current = pq.top();//Reachable Node with least weight
        pq.pop();
        int node = current.second.first;
        int prevNode = current.second.second;
        int weight = current.first;
        if(visited[node] == true) continue;
        visited[node] = true;
        cost += weight;
        mst.push_back({node, prevNode});
        for(auto i : g->getNeighbors(node))
        {
            //getNeighbors returns vector of pairs in format {node, edgeWeight}
            pq.push({i.second, {i.first, node}});
        }
    }
    cout<<"Cost of MST is "<<cost<<endl;
    return mst;
}
int main(void)
{

    vector<pair<int, int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {1, 4}, {1, 3} };
    int weight[] = {1, 4, 2, 6, 7, 5, 3};
    Graph* g = new Graph(1001, true);
    for(int i = 0;i < 7;i++)
    {
        g->connect(edges[i].first, edges[i].second, weight[i]);
    }
    vector<pair<int, int>> mst = Prim(g);
    for(auto i : mst)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}