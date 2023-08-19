//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here  
            vector<int> adj[n];
            int indgr[n];
            memset(indgr,0,sizeof(indgr));
            for(auto it: edges){
                adj[it[0]-1].push_back(it[1]-1);
                indgr[it[1]-1]++;
            }
            vector<int> time(n,-1);
            queue<int> q;
            for(int i = 0; i< n;i++){
                if(indgr[i] == 0){
                    q.push(i);
                    time[i] = 1;
                }
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto it: adj[node]){
                    indgr[it]--;
                    if(indgr[it] == 0){
                        time[it] = time[node]+1;
                        q.push(it);
                    }
                }
            }
            return time;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends