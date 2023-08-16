//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int vis[100000];
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        memset(vis,0,sizeof(vis));
        for(int i = 0;i< V;i++){
            // cout<<adj[1][i]<<endl;
            if(vis[i] == 0){
                if(detect(i,V,adj)) return true;
            }
        }
        return false;
    }
    bool detect(int node, int V, vector<int> adj[]){
        vis[node] = 2;
        for(auto i : adj[node]){
            // cout<<adj[node][i]<<endl;
            if(vis[i] == 0){
                if(detect(i,V,adj)) return true;
            }
            else if(vis[i] == 2){
                return true;
            }
        }
        vis[node] =1;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends