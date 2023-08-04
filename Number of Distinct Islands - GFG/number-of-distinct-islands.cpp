//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int vis[500][500];
    int dRow[4] = {1,-1,0,0};
    int dCol[4] = {0,0,1,-1};
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        memset(vis,0,sizeof(vis));
        set<vector<pair<int,int>>> u;
        int cnt =0; 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n;j++){
                if(!vis[i][j] and grid[i][j]){
                    vector<pair<int,int>> curr;
                    dfs(i,j,grid,curr,i,j);
                    // for(auto it : curr){
                    //     cout<<it.first<<" "<< it.second<<endl;

                    // }
                    // cout<<endl;
                    u.insert(curr);
                }
            }
        }
        return u.size();
    }
    
    void dfs(int r, int c, vector<vector<int>> &grid, vector<pair<int,int>> &curr, int iSrc, int jSrc){
        
        vis[r][c] =1;
        curr.push_back({r-iSrc,c-jSrc});
        
        for(int i = 0; i<4;i++){
            
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            
            bool inGrid = nRow >=0 and nRow < grid.size() and nCol >=0 and nCol <grid[0].size();
            
            if(inGrid and grid[nRow][nCol] and !vis[nRow][nCol]){
                dfs(nRow,nCol,grid,curr,iSrc,jSrc);
            }
        }
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends