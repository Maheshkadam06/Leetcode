//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int vis[100];    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //  bfs
        memset(vis,0,sizeof(vis));
        vector<vector<pair<int,int>>> adj(N,vector<pair<int,int>>());
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        //  toposort by dfs
        stack<int> topo;
        for(int i = 0; i< N;i++){
            if(!vis[i]){
                dfs(i,adj,topo);
            }
        }
        vector<int> dist(N,INT_MAX);
        int src = 0;
        dist[src] = 0;
        
        while(!topo.empty()){
            int node = topo.top();
            topo.pop();
            if(dist[node] == INT_MAX){
                continue;
            }
            for(auto it: adj[node]){
                dist[it.first] = min(dist[it.first],dist[node]+it.second);
            }
        }
        vector<int> ans;
        for(int i = 0; i< N;i++){
            if(dist[i] == INT_MAX) dist[i] =-1;
            ans.push_back(dist[i]);
        }
        return ans;
    }
    void dfs(int node,vector<vector<pair<int,int>>> &adj,stack<int> &topo){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                dfs(it.first,adj,topo);
            }
        }
        topo.push(node);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends