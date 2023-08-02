//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> ans;
        queue<int> bfs;
        bfs.push(0);
        vis[0]=1;
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    bfs.push(it);
                    // you dont't add it again once it is in queue 
                    vis[it] =1;
                }
                
            }
        }
        return ans;
    }
    
    // void bfs(int node, vector<int> adj[],int vis[],vector<int> &ans){
    //     vis[node] =1;
    //     for(auto it: adj[node]){
    //         if(!vis[it]){
    //             bfs(it,adj,vis,ans);
    //         }
    //     }
    // }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends