/**
Given an undirected graph and an edge, the task is to find if the given edge is a bridge in graph, 
i.e., removing the edge disconnects the graph.

Refer: http://www.geeksforgeeks.org/bridge-in-a-graph/
**/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w);
    bool isBridge(int u, int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Driver Program
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int s,N;
        cin>>s>>N;
        Graph *g = new Graph(s);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        int a,b;
        cin>>a>>b;
        if(g->isBridge(a, b))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

int tval = 0;

void check_bridge(int s, list<int> *adj, vector<int> &low, vector<int> &disc, vector<int> &marked, vector<int> &parent){
    low[s] = disc[s] = ++tval;
    // cout<<tval;
    marked[s] = true;
    for(list<int>::iterator it=adj[s].begin(); it!=adj[s].end(); it++){
        int t = *it;
        if(!marked[t]){
            parent[t] = s;
            check_bridge(t, adj, low, disc, marked, parent);
            low[s] = min(low[t], low[s]);
            
        }else if(t != parent[s]) low[s] = min(low[s], disc[t]);
        
    }
}

bool Graph::isBridge(int u, int v)
{
    vector<int> low(V), disc(V), parent(V);
    vector<int> marked(V, false);
    
    marked[u] = true;
    parent[v] = u;
    
    low[u] = disc[u] = ++tval;
    check_bridge(v, adj, low, disc, marked, parent);
    if(low[v] > disc[u] ) return 1;
    return 0;
}