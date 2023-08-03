#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<int,int> Pair;
vector<Pair> adj[100001];
int dist[100001];

void dijkstra(int source)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    pq.push(make_pair(0, source));
    dist[source] = 0;


    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(int i=0; i<adj[u].size(); i++)
        {

            int weight = adj[u][i].first;
            int vertex = adj[u][i].second;


            if (dist[vertex] > dist[u] + weight)
            {

                dist[vertex] = dist[u] + weight;
                pq.push(make_pair(dist[vertex], vertex));
            }
        }
    }
}

int main()
{

    int nodes, edges, source;
    cin >> nodes >> edges >> source;


    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;


        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }


    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }


    dijkstra(source);


    for (int i = 1; i <= nodes; i++)
    {
        cout << "Shortest distance from node " << source << " to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}
/* enter input:
5 8 0
0 1 4
0 2 4
1 2 2
2 3 3
2 4 1
3 4 2
4 5 3
2 5 6
*/

/*
Shortest distance from node 0 to node 1 is 4
Shortest distance from node 0 to node 2 is 4
Shortest distance from node 0 to node 3 is 7
Shortest distance from node 0 to node 4 is 5
Shortest distance from node 0 to node 5 is 8
*/

