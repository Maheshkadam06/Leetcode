//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
        //  Code Here
        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
        for(int i = 0; i<E;i++){
            //  need to check this
            adj[a[i*3]].push_back({a[i*3+1],a[i*3+2]});
            adj[a[i*3+1]].push_back({a[i*3],a[i*3+2]});
            // cout<<a[i*3]<<" "<< a[i*3+1]<<" "<<a[i*3+2]<<endl;
        }
        int vis[V];
        memset(vis,0,sizeof(vis));
        return dfs(0,adj,vis,0,k);
    } 
    bool dfs(int node,vector<vector<pair<int,int>>> &adj,int vis[],int cost,int K){
        if(cost>=K){
            return true;
        }
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it.first]){
                if(dfs(it.first,adj,vis,cost+it.second,K)) return true;
            }
        }
        vis[node] = 0;
        return false;
    }
    
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends