//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int mod = 1e9+7;
vector<int> dp[100][100];
vector<int> FindWays(vector<vector<int>>&matrix){
    // Code here
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            dp[i][j] = {}; // Initialize an empty vector
        }
    }
    vector<int> temp = solve(0,0,matrix);
    if(temp[0] == 0) return {0,0};
    return temp;
    
}
vector<int> solve(int r, int c,vector<vector<int>>&matrix){
    if(r > matrix.size()-1 or c > matrix[0].size()-1){
        return {0,0};
    }
    if(r == matrix.size()-1 and c == matrix[0].size()-1){
        return  {1,matrix[r][c]};
    }
    if(dp[r][c].size() != 0) return dp[r][c];
    if(matrix[r][c] == 1){
        vector<int> temp = solve(r,c+1,matrix);
        if(temp[0] == 0)  return  dp[r][c] = {0,0};
        return dp[r][c] = {temp[0],temp[1]+1};
    }
    else if(matrix[r][c] == 2){
        vector<int> temp = solve(r+1,c,matrix);
        if(temp[0] == 0)  return dp[r][c] = {0,0};
        return dp[r][c] = {temp[0],temp[1]+2};
    }
    
    vector<int> temp1 = solve(r+1,c,matrix);
    if(temp1[0] == 0) temp1  =  {0,0};
    
    vector<int> temp2 = solve(r,c+1,matrix);
    if(temp2[0] == 0) temp2 =  {0,0};
    // if(temp1[1]==temp2[1]){return {temp1[0]+temp2[0],temp1[1]+3};}
    // if(temp1[1] > temp2[1]){return {temp1[0],temp1[1]+3};}
    // return {temp2[0],temp2[1]+3};
    long int ans = (temp1[0]+temp2[0])%mod;
    return dp[r][c] = {ans,max(temp1[1],temp2[1])+3};
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends