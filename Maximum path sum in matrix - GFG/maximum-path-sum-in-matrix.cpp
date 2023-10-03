//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[500][500];
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int mx = 0;
        memset(dp,-1,sizeof(dp));
        for(int c = 0; c < Matrix[0].size();c++){
            mx = max(mx,drop(0,c,N,Matrix));
        }
        return mx;
        
    }
    int drop(int r, int c, int n, vector<vector<int>>&mat){
        if(r == n) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int dc[3] = {0,-1,1};
        int mx = 0;
        for(int i = 0; i < 3; i++){
            int nr = r+1;
            int nc = c+dc[i];
            bool ingrid = nc >=0 and nc < mat[0].size() and nr < mat.size();
            if(ingrid){
                mx = max(mx,drop(nr,nc,n,mat));
            }
        }
        // cout<<mx<<endl;
        return dp[r][c] = mat[r][c]+mx;
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