//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int a = INT_MAX,b= INT_MAX;
    for(int i =0; i< n;i++){
        if(arr[i] == x){
            return {x,x};
        }
        if(arr[i]>x){
            a = min(arr[i]-x,a);
        }
        else{
            b = min(b,x-arr[i]);
        }
        
    }
    
    if(a == INT_MAX) return {x-b,-1};
    if(b == INT_MAX) return {-1,x+a}; 
    
    return {x-b,x+a};
}