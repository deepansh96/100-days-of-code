/*
There are M job applicants and N jobs. Each applicant has a subset of jobs that he/she is interseted in. 
Each job opening can only accept one applicant and a job applicant can be appointed for only one job. 
Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.

Refer: http://www.geeksforgeeks.org/maximum-bipartite-matching/
*/

#include <bits/stdc++.h>
using namespace std;
#define M 100
#define N 100

bool mbm(bool bpGraph[M][N], int j, int i, vector<bool> &marked, vector<int> &job){
    for(int n=0; n<j; n++){
        if(bpGraph[i][n] > 0 && !marked[n]){
            marked[n] = true;
            if(job[n] < 0 || mbm(bpGraph, j, job[n], marked, job)){
                job[n] = i;
                return true;
            }
            marked[n] = false;
        }
    }
    
    return false;
}

int maxBPM(bool bpGraph[M][N],int m,int n)
{
//add code here.
    vector<int> job(n, -1);
    int res = 0;
    
    for(int i=0; i<m; i++){
        vector<bool> marked(n, false);
        if(mbm(bpGraph, n, i, marked, job)) res++;
    }
    
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;      
        bool bpGraph[M][N];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>bpGraph[i][j];
        cout << maxBPM(bpGraph,m,n)<<endl;
    }
    return 0;
}