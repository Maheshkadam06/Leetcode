//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int vis[500][500];
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        for(int r = 0;r< grid.size();r++){
            for(int c = 0;c<grid[0].size();c++){
                if(!vis[r][c] and grid[r][c] == '1'){
                    dfs(r,c,grid);
                    cnt++;
                }
            }
        }
        return cnt;
        
        
    }
    void dfs(int r, int c,vector<vector<char>>& grid){
        vis[r][c] = 1;
        int dR[8] = {1,1,1,-1,-1,-1,0,0};
        int dC[8] = {-1,0,1,-1,0,1,-1,1};
        for(int i = 0; i< 8;i++){
            int nr = r + dR[i];
            int nc = c+ dC[i];
            bool inGrid = nr>= 0 and nc>=0 and nr<grid.size() and nc<grid[0].size();
            
            if(inGrid and !vis[nr][nc] and grid[nr][nc] == '1'){
                dfs(nr,nc,grid);
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends