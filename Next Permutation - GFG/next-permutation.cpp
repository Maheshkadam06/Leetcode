//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        vector<int> ans;
        int r = n-1;
        for(r = n-2; r>=0;r--){
            if(arr[r+1]>arr[r]){
                break;
            }
        }
        // cout<<r<<endl;
        if(r==-1){
            for(int j = n-1;j>=0;j--){
                ans.push_back(arr[j]);
            }
            return ans;
        }
        int k;
        for(k = n-1; k>r;k--){
            if(arr[k]> arr[r]){
                break;
            }
        }
        int temp = arr[r];
        arr[r] = arr[k];
        arr[k] = temp;
        for(int i=0; i<=r;i++){
            ans.push_back(arr[i]);
        }
        for(int j = n-1;j>r;j--){
            ans.push_back(arr[j]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends