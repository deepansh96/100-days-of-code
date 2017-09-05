/**
Given an adjacency matrix and 2 integers S and T. The task is to find minimum capacity s-t cut of the given network. 
An s-t cut is a cut that requires the source ‘s’ and the sink ‘t’ to be in different subsets, and it consists of edges 
going from the source’s side to the sink’s side. The capacity of an s-t cut is defined by the sum of capacity of each edge 
in the cut-set. 

Refer: http://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj, graph;
vector<int> parent;
vector<bool> marked;

void bfs(int s, int v){
    marked[s] = true;
    queue<int> q;
    q.push(s);
    parent[s] = s;
    // cout<<"Q.size():"<<q.size()<<endl;
    // cout<<"s="<<s<<endl;
    while(!q.empty()){
        
        int n = q.front();
        // cout<<n<<" "<<q.size()<<endl;
        q.pop();
        for(int u=0; u<v; u++){
            // cout<<u<<" "<<marked[u]<<endl;
            // cout<<u<<" "<<adj[n][u]<<endl;
            if(marked[u] || adj[n][u] == 0) continue;
            // cout<<n<<" "<<u<<endl;
            marked[u] = true;
            parent[u] = n;
            q.push(u);
        }
    }
    
    return;
}

vector<pair<int, int> > solve(int s, int t, int v){
    adj = graph;
    // cout<<adj[0][1]<<endl;
    // cout<<graph[0][1]<<endl;
    while(true){
        // cout<<1;
        fill(marked.begin(), marked.end(), false);
        bfs(s, v);
        if(!marked[t]) break;
        int temp = t;
        int minv = INT_MAX;
        while(parent[temp] != temp){
            int p = parent[temp];
            minv = min(minv, adj[p][temp]);
            temp = p;
        }
        
        temp = t;
        while(parent[temp] != temp){
            int p = parent[temp];
            adj[p][temp] -= minv;
            adj[temp][p] += minv;
            temp = p;
        }
    }
    vector<pair<int, int> > res;
    fill(marked.begin(), marked.end(), false);
    bfs(s, v);
    for(int i=0; i<v; i++){
        if(marked[i]){
            // cout<<i<<endl;
            for(int j=0; j<v; j++){
                if(!marked[j] && graph[i][j] > 0) res.push_back(make_pair(i, j));
            }
        }
    }
    return res;
}

int main() {
    int tu, v, s, t;
    cin>>tu;
    while(tu-- > 0){
        cin>>v;
        adj.clear();
        graph.clear();
        parent.clear();
        marked.clear();
        graph.resize(v, vector<int>(v));
        adj.resize(v, vector<int>(v));
        parent.resize(v);
        marked.resize(v);
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cin>>graph[i][j];
            }
        }
        cin>>s>>t;
        vector<pair<int, int> > res = solve(s, t, v);
        // cout<<res.size()<<endl;
        for(int i=0; i<res.size(); i++){
            cout<<res[i].first<<" "<<res[i].second<<" ";
        }
        cout<<endl;
        
    }
	return 0;
}