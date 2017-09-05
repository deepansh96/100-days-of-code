/**
Given a graph with N vertices numbered 1 to N and M edges, the task is to find the max flow from vertex 1 to vertex N.

Refer: http://www.geeksforgeeks.org/push-relabel-algorithm-set-1-introduction-and-illustration 
**/

#include <bits/stdc++.h>
using namespace std;

bool push(int graph[1000][1000], vector<int> &height, vector<int> &flow, int s, int n){
    bool f = false;
    for(int i=0; i<n; i++){
        if(graph[s][i] > 0 && height[s] > height[i]){
            f = true;
            int val = min(graph[s][i], flow[s]);
            flow[s] -= val;
            flow[i] += val;
            graph[s][i] -= val;
            graph[i][s] += val;
            break;
        }
    }
    return f;
}

void relabel(int graph[1000][1000], vector<int> &height, int s, int n){
    int minv = INT_MAX;
    for(int i=0; i<n; i++){
        if(graph[s][i] > 0) minv = min(minv, height[i]);
    }
    height[s] = minv + 1;
    return;
}


int push_relabel(int graph[1000][1000], vector<int> height, int s,int t,int n){
    height[s] = n;
    vector<int> flow(1000, 0);
    for(int i=0; i<n; i++){
        if(graph[s][i] > 0) {
            flow[i] = graph[s][i];
            flow[s] -= flow[i];
            graph[s][i] = 0;
            graph[i][s] = flow[i];
        }
    }
    
    while(true){
        int v = -1;
        for(int i=0; i<n; i++){
            if(marked[i]) continue;
            marked[i] = true;
            count++;
            if(flow[i] > 0){
                v = i;
                // cout<<i<<"-"<<flow[i]<<endl;
                break;
            }
        }
        // cout<<v;
        if(v == -1) break;
        if(push(graph, height, flow, v, n)) {
             if(count == n){
                count = 2;
                fill(marked.begin(), marked.end(), false);
                marked[s] = true;
                marked[t] = true;
            }
            continue;
        }
        marked[v] = false;
        count--;
        relabel(graph, height, v, n);
        // cout<<"HEIGHT = "<<height[v]<<endl;
        
       
    }
    
    return (-1) * flow[s];
} 
 
 
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int graph[1000][1000];
	    vector<int> height(n, 0);
	    memset(graph,0,sizeof(graph));
	    for(int i=0;i<m;i++){
	        int x,y,z;
	        cin>>x>>y>>z;
	        
	            graph[x-1][y-1]+=z;
	           // graph[y-1][x-1]+=z;
	         
	    
	    }
	    cout<<push_relabel(graph,height,0,n-1,n);
	    cout<<endl;
	}
	return 0;
}