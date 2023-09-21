//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int last[2][W+1];
       memset(last,0,sizeof(last));
       
       for(int i = 0; i<n;i++){
           for(int j = 0; j<=W;j++){
               if(j-wt[i]>=0){
                   last[1][j] = last[0][j-wt[i]]+val[i];
               }
               last[1][j]= max(last[1][j],last[0][j]);
           }
           for(int k =0; k<=W;k++) last[0][k] = last[1][k];
       }
       return last[0][W];
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