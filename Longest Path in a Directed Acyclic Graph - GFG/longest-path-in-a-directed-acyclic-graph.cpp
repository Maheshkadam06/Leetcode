//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            vector<vector<int>> adj[v];
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                adj[u].push_back({v,wt});
            }
            //  topological sort
            stack<int> topo;
            int vis[v];
            memset(vis,0,sizeof(vis));
            dfs(src,adj,vis,topo);
            vector<int> dist(v,INT_MIN);
            dist[src] = 0;
            while(!topo.empty()){
                int node = topo.top();
                topo.pop();
                
                for(auto it: adj[node]){
                    int adjNode = it[0];
                    int edgWt = it[1];
                    if(dist[adjNode] < dist[node] + edgWt){
                        dist[adjNode] = dist[node] + edgWt;
                    }
              }
          }
          return dist;
            
      }
      void dfs(int node, vector<vector<int>> adj[],int vis[],stack<int> &topo){
          vis[node] = 1;
          for(auto it: adj[node]){
              if(!vis[it[0]]){
                  dfs(it[0],adj,vis,topo);
              }
          }
          topo.push(node);
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends