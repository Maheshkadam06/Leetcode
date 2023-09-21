//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   // Your code here
        memset(dp,-1,sizeof(dp));
        return solve(0,W,wt,val,n);
    
    //   return 0;
    }
    int solve(int i, int W, int wt[], int val[], int n){
        if(i >= n) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        int mx = 0;
        if(W >= wt[i]){
            mx = solve(i+1,W-wt[i],wt,val,n)+val[i];
        }
        mx = max(mx,solve(i+1,W,wt,val,n));
        return dp[i][W]= mx;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends