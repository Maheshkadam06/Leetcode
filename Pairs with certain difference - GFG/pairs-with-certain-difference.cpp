//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int dp[10000];
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here 
        memset(dp,-1,sizeof(dp));
        sort(arr,arr+N);
        return solve(0,N,K,arr);
    }
    
    int solve(int i, int N, int K, int arr[]){
        if(i >= N-1) return 0;
        if(dp[i] != -1) return dp[i];
        int picked = 0;
        if(arr[i+1]-arr[i] <K){
            picked = solve(i+2,N,K,arr) + arr[i]+arr[i+1];
        }
        int ignored = solve(i+1,N,K,arr);
        
        return dp[i]= max(picked,ignored);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends