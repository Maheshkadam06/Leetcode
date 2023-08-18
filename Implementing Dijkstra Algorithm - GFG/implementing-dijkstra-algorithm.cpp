//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        // priotity queue
        // vector<int> dist(V,INT_MAX);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // dist[src] = 0;
        // pq.push({0,src});
        
        // while(!pq.empty()){
        //     int node = pq.top().second;
        //     int dis = pq.top().first;
        //     pq.pop();
            
        //     for(auto it : adj[node]){
        //         int adjNode = it[0];
        //         int edgWt = it[1];
        //         if(dist[node] + edgWt < dist[adjNode]){
        //             dist[adjNode] = dist[node] + edgWt;
        //             pq.push({dist[adjNode],adjNode});
        //         }
        //     }
        // }
        // return dist;
        
        
        //  use set now
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> st;
        //  set also store in asceding order
        dist[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            // chose first element as it stored in ascending order
            // just because set has erase function nothing different from pq
            auto it = *(st.begin());
            int node = it.second;
            int dis =it.first;
            st.erase({dis,node});
            
            for(auto i : adj[node]){
                int adjNode = i[0];
                int edgWt = i[1];
                
                if(dis+edgWt < dist[adjNode]){
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis+edgWt;
                    st.insert({dist[adjNode],adjNode});
                }
            }
            
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends