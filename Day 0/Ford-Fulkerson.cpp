/**
Given a graph with N vertices numbered 1 to N and M edges, the task is to find the max flow from vertex 1 to vertex N.

Refer: http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
**/

#include<bits/stdc++.h>
using namespace std;
 
bool bfs(int rgraph[1000][1000],int s,int t,int n,int parent[]){
 
    bool visited[n];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
 
    while(!q.empty()){
 
        int u=q.front();
        q.pop();
 
        for(int v=0;v<n;v++){
 
            if(!visited[v] && rgraph[u][v]>0){
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
 
    }
    return (visited[t]==true);
}
int maxflow(int graph[1000][1000],int s,int t,int n){
 
    int parent[n];
    int u,v;
    int max_flow=0;
    int rgraph[1000][1000];
    for(u=0;u<n;u++)
        for(v=0;v<n;v++)
            rgraph[u][v]=graph[u][v];
 
    while(bfs(rgraph,s,t,n,parent)) {
 
        int path_flow=INT_MAX;
 
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rgraph[u][v]);
        }
       // cout<<path_flow<<" ";
         for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            rgraph[u][v]=rgraph[u][v]-path_flow;
            rgraph[v][u]=rgraph[v][u]+path_flow;
       }
       
        
       max_flow+=path_flow;
    }   
    return max_flow;
} 
 
 
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int graph[1000][1000];
	    memset(graph,0,sizeof(graph));
	    for(int i=0;i<m;i++){
	        int x,y,z;
	        cin>>x>>y>>z;
	        
	            graph[x-1][y-1]+=z;
	            graph[y-1][x-1]+=z;
	         
	    
	    }
	    cout<<maxflow(graph,0,n-1,n);
	    cout<<endl;
	}
	return 0;
}