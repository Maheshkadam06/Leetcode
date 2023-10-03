//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(2,vector<int>(Matrix[0].size(),0));
        for(int r = 0; r <N;r++){
            for(int c = 0; c<Matrix[0].size();c++){
                int dc[3] = {0,-1,1};
                for(int i = 0; i < 3; i++){
                    int nc = c+dc[i];
                    bool ingrid = nc >=0 and nc < Matrix[0].size();
                    if(ingrid){
                        dp[1][c] = max(dp[1][c], Matrix[r][c]+dp[0][nc]);
                    }
                }
            }
            for(int c = 0; c<Matrix[0].size();c++) dp[0][c] = dp[1][c];
        }
        
        int mx = 0;
        for(int c = 0; c<Matrix[0].size();c++) mx = max(mx,dp[0][c]);
        return mx;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends