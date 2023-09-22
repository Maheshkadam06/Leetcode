//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    int dp[1001];
    int nCr(int n, int r){
        // code here
        memset(dp,-1,sizeof(dp));
        long long num = 1;
        for(int i = n; i>(n-r);i--){
            num = (num*i)%mod;
        }
        long long denom = 1;
        
        for(int i = 1; i <= r;i++){
            denom = (denom*i)%mod;
        }
        // cout<<num<<" "<<denom<<endl;
        
        return (num*pow(denom,mod-2))%mod;
    }
    
    long long pow(long long i, int m){
        if(m == 0) return 1;
        long long ans = pow(i,m/2);
        ans = (ans*ans)%mod;
        if(m%2){
            return (ans*i)%mod;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends