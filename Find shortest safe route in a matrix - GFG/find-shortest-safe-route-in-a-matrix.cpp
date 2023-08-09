//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       vector<vector<int>> mat2(mat.begin(),mat.end());
       int ans = -1;
       int dR[4] = {1,-1,0,0};
       int dC[4] = {0,0,+1,-1};
       for(int i =0; i< mat.size();i++){
           for(int j = 0;j< mat[0].size();j++){
               if(mat[i][j] == 0){
                   for(int k = 0; k<4;k++){
                       int nr = i+dR[k];
                       int nc = j+dC[k];
                       bool isSafe = nr>= 0 and nr<mat.size() and nc>=0 and nc<mat[0].size();
                       
                       if(isSafe){
                           mat2[nr][nc] =0;
                       }
                   }
               }
           }
       }
       
       int vis[1000][1000];
       memset(vis,0,sizeof(vis));
       
       queue<vector<int>> q;
       for(int r = 0;r<mat.size();r++){
           if(mat2[r][0]){
               q.push({r,0,1});
               vis[r][0] = 1;
           }
       }
       while(!q.empty()){
           int r = q.front()[0];
           int c = q.front()[1];
           int moves = q.front()[2];
           
           q.pop();
           if(c == mat[0].size()-1){
              ans = moves; 
              break;
           }
           
           for(int i =0;i< 3; i++ ){
               int nr = r+ dR[i];
               int nc = c+ dC[i];
               bool isSafe = nr>= 0 and nr<mat.size() and nc>=0 and nc<mat[0].size() and mat2[nr][nc] and !vis[nr][nc];
               if(isSafe){
                   vis[nr][nc] = 1;
                   q.push({nr,nc,moves+1});
               }
           }
       }
       
       return ans;
       

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends