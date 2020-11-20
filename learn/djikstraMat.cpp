#include<bits/stdc++.h>
using namespace std;
int getMinVertex(vector<int>& distances, vector<bool>& visited)
{
    int minDistance = INT_MAX;
    int vertex = 0;
    for(int i = 0;i < distances.size();i++)
    {
        if(visited[i] == false && distances[i] < minDistance)
        {
            vertex = i;
            minDistance = distances[i];
        }
    }
    return vertex;
}
void djikstra(vector<vector<int>>& Graph, int source)
{
    int vertices = Graph.size();
    vector<int> distances(vertices, 9999);
    vector<bool> visited(vertices, false);
    vector<int> prev(vertices, source);
    distances[source] = 0;
    int current = source;
    for(int i = 0;i < vertices;i++)
    {
        int minVertex = getMinVertex(distances, visited);
        visited[minVertex] = true;
        for(int j = 0;j < vertices;j++)
        {
            if(visited[j] == false && Graph[minVertex][j] != 0 && distances[j] > distances[minVertex] + Graph[minVertex][j])
            {
                distances[j] = distances[minVertex] + Graph[minVertex][j];
                prev[j] = minVertex;
            }
        }
    }
    cout<<"Min distance from source is\n"<<endl;
    for(int i = 0;i < distances.size();i++)
    {
        cout<<"From "<<i<<" : "<<distances[i]<<" prev node is "<<prev[i]<<endl;
    }
}
int main(void)
{
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
        {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
        {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
        {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
    };
    djikstra(graph, 0);
}