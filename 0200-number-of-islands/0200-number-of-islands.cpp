class Solution {
public:
    int vis[300][300];
    int dRow[4] = {1,-1,0,0};
    int dCol[4] = {0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        memset(vis,0,sizeof(vis));
        
        int cnt =0; 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n;j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
    void dfs(int r, int c, vector<vector<char>> &grid){
        
        vis[r][c] =1;
        
        for(int i = 0; i<4;i++){
            
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            
            bool inGrid = nRow >=0 and nRow < grid.size() and nCol >=0 and nCol <grid[0].size();
            
            if(inGrid and grid[nRow][nCol] == '1' and !vis[nRow][nCol]){
                dfs(nRow,nCol,grid);
            }
        }
        
    }
};