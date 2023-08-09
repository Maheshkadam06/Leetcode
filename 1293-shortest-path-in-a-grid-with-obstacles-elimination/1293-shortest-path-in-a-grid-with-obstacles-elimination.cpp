class Solution {
public:
    // int vis[40][40];
    int vis[40][40][1600+1];
    int dR[4] = {1,0,0,-1};
    int dC[4] = {0,1,-1,0};
    
    int shortestPath(vector<vector<int>>& grid, int kmax) {
        // memset(vis,0,sizeof(vis));
        // int ans = INT_MAX;
        // solve(0,0,grid,k,0,grid.size(),grid[0].size(),ans);
        // if(ans == INT_MAX) return -1;
        // return ans;
        
        
//          BFS
        int m = grid.size();
        int n = grid[0].size();
        
        
        memset(vis,-1,sizeof(vis));
        
        
        
        queue<vector<int>> q;
        q.push({0,0,kmax});
        vis[0][0][kmax] = 0;
        int ans = -1;
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int k = q.front()[2];
            
            q.pop();
            int moves = vis[r][c][k];
            // cout<<r<<" "<<c<<" "<<k <<" "<<moves<<endl;
            
            
            if(r == m-1 and c == n-1){
                    ans = moves;
                    break;
                }
            
            for(int i = 0; i< 4; i++){
                int nr = r+ dR[i];
                int nc = c+ dC[i];
                bool isSafe = nr>= 0 and nr<m and nc>=0 and nc<n;
            
//                 if(isSafe and grid[r][c] == 1){
//                     if(vis[nr][nc][k+1] == moves-1) {continue;}
//                 }
//                 else if(isSafe){
//                     if(vis[nr][nc][k] == moves-1) continue;
//                 }
                
//                 if(isSafe and grid[nr][nc] == 1 and k-1>=0 and  vis[nr][nc][k-1] == -1){
//                     vis[nr][nc][k-1] = moves+1;
//                     q.push({{nc,nr},k-1});
//                 }
//                 if(isSafe and grid[nr][nc] == 0 and vis[nr][nc][k] == -1){
//                     vis[nr][nc][k] = moves+1;
//                     q.push({{nc,nr},k});
//                 }
//                 // cout<<q.front
                
                
                
                if(isSafe){
                    if(grid[nr][nc] == 1){
                        // if(vis[nr][nc][k+1] == moves-1) {continue;}
                        if(k -1 >= 0 and vis[nr][nc][k-1] == -1){
                            vis[nr][nc][k-1] = moves+1;
                            // cout<<vis[nr][nc][k-1]<<endl;
                            q.push({nr,nc,k-1});
                        }
                    }
                    else{
                        // if(vis[nr][nc][k] == moves-1) continue;
                        if(vis[nr][nc][k] == -1){
                            vis[nr][nc][k] = moves+1;
                            // cout<<vis[nr][nc][k]<<endl;
                            q.push({nr,nc,k});
                        }
                    }
                }
            }
            
            
            
        }
        
        return ans;        
    }
    
//     void solve(int R, int C, vector<vector<int>>& grid, int k, int steps,int m, int n, int &ans){
//         if(ans == m+n-2) return;
//         vis[R][C] = 1;
//         if(R == m-1 and C == n-1){
//             ans = min(ans,steps);
//             return;
//         }
//         if(steps>= ans) return;
//         for(int i = 0;i<4;i++){
//             int nR = R + dR[i];
//             int nC = C + dC[i];
//             bool isSafe = nR>= 0 and nR < m and nC >= 0 and nC<n;
            
//             if(isSafe and !vis[nR][nC]){
                
//                 if(grid[nR][nC] == 1){
//                     if(k>0){k -=1;}
//                     else{continue;}
//                 } 
//                 vis[nR][nC]=1;
//                 solve(nR,nC,grid,k,steps+1,m,n,ans);
//                 if(grid[nR][nC] == 1) k+=1;
//                 vis[nR][nC] =0;
//             }
//         }
        
        
        
    // }
};