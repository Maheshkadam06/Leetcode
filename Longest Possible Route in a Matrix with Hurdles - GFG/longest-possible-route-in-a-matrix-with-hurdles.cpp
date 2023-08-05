//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int vis[10][10];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        memset(vis,0,sizeof(vis));
        int ans  = -1;
        vis[xs][ys] =1;
        if(matrix[xd][yd] == 0 or matrix[xs][ys] == 0 ) return -1;
        solve(xs,ys,0,matrix,xd,yd, ans);
        return ans;
        
    }
    
    void solve(int x,int y,int move, vector<vector<int>> &matrix,int &xd, int &yd, int &ans){
        if(x == xd and y == yd){
            ans = max(ans,move);
        }
        
        for(int i = 0 ; i< 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            bool fit = nx >= 0 and ny >= 0 and nx < matrix.size() and ny < matrix[0].size();
            
            if(fit and !vis[nx][ny] and matrix[nx][ny] == 1){
                vis[nx][ny] =1;
                solve(nx,ny,move+1,matrix,xd,yd,ans);
                vis[nx][ny] =0;
            }
        }
        
        
        
        
    }
    
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends