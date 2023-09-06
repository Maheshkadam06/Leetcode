//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> ans;
            for(int i = 0; i<n1;i++){
                if(i != 0 and A[i] == A[i-1]) continue;
                int target = A[i];
                if(binary_search(0,n2-1,B,target) != -1){
                    if(binary_search(0,n3-1,C,target) != -1){
                        ans.push_back(A[i]);
                    }
                }
            }
            return ans;
        }
        int binary_search(int low, int high, int arr[], int target){
            if(low <=high){
                int  mid = (low + high)/2;
                if(arr[mid] == target){
                    return mid;
                }
                if(arr[mid]> target){
                    return binary_search(low,mid-1,arr,target);
                }
                else{
                    return binary_search(mid+1,high,arr,target);
                }
            }
            return -1;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends