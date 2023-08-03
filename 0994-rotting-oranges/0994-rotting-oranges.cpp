class Solution {
public:
    int vis[10][10];
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> level(grid.size(),vector<int>(grid[0].size(),INT_MAX));
//             bfd
        
        for(int m = 0;m < grid.size();m++){
            for(int n = 0; n< grid[0].size();n++){
                if(grid[m][n] == 2){
                    bfd(m,n,grid,level);
                }
            }
        }
        int mx = 0;
        for(int m = 0;m < grid.size();m++){
            for(int n = 0; n< grid[0].size();n++){
                
                if(grid[m][n] != 0){
                    if(level[m][n] == INT_MAX) return -1;
                    mx = max(mx,level[m][n]);
                }
            }
        }
        return mx;
        
    }
    void bfd(int m ,int n,vector<vector<int>>& grid,vector<vector<int>> &level){
        memset(vis,0,sizeof(vis));
        queue<vector<int>> bfd;
        bfd.push({m,n,0});
        vis[m][n] = 1;
        while(!bfd.empty()){
            vector<int> temp = bfd.front();
            // for()
            bfd.pop();
            int i = temp[0], j = temp[1],k = temp[2];
            level[i][j] = min(k,level[i][j]);
            
            if(i+1< grid.size() and !vis[i+1][j] and grid[i+1][j]==1){ 
                vis[i+1][j]=1;bfd.push({i+1,j,k+1});}
            if(i-1>= 0 and !vis[i-1][j] and grid[i-1][j]==1){
                vis[i-1][j]=1;bfd.push({i-1,j,k+1});}
            if(j+1< grid[0].size() and !vis[i][j+1] and grid[i][j+1]==1){
                vis[i][j+1]=1;bfd.push({i,j+1,k+1});}
            if(j-1 >= 0 and !vis[i][j-1] and grid[i][j-1]==1){
                vis[i][j-1] =1;bfd.push({i,j-1,k+1});}
            
                      
        }
        
    }
};