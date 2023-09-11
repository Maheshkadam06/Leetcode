//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int l = 0;
        int r = 1e9;
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(fit(stalls,mid,k)){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    bool fit(vector<int> &stalls, int gap,int k){
        int last = stalls[0];
        k--;
        for(int i =1; i < stalls.size();i++){
            if(k==0) break;
            if(stalls[i] - last >= gap){
                k--;
                last = stalls[i];
            }
        }
        return k==0;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends