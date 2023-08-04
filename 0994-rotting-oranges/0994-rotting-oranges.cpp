class Solution {
public:
    int level[10][10];
    int vis[10][10];
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        memset(level,0,sizeof(level));  
        memset(vis,0,sizeof(vis));  
        
        queue <pair<pair<int,int>,int>> q;
        // ((row,col),level);
            
        int cnt = 0;
        
        for(int i = 0; i<m;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j] ==1) cnt++;
            }
        }
        
        int dR[] = {1,-1,0,0};
        int dC[] = {0,0,1,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            level[r][c] = t;
            
            for(int i = 0; i < 4;i++){
                int Row = r+dR[i];
                int Col = c+dC[i];
                if(Row>=0 and Row < m and Col >=0 and Col < n and !vis[Row][Col] and grid[Row][Col] == 1){
                     q.push({{Row,Col},t+1});
                    cnt--;
                    vis[Row][Col] =1;
                }
            }   
        }
        if(cnt != 0) return -1;
        int mx = 0;
        
        for(int i = 0; i<m;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    mx = max(mx,level[i][j]);
                }
            }
        }
        return mx;
    }
};