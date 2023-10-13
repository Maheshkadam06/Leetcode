//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        int prev2 = 0;
        int prev = 0;
        int curr = 0;
        sort(arr,arr+N);
        for(int i = 1; i < N;i++){
            curr = prev;
            if(arr[i]-arr[i-1] <K){
                curr = max(curr,prev2+arr[i]+arr[i-1]);
            }
            prev2 = prev;
            prev =  curr;
        }
        return curr;
        
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