//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int l = 0, r= 0;
    int cnt =0;
    vector<int> freq(255,0);
    int ans = -1;
    while(r<s.size()){
        if(freq[s[r]] ==0){
            cnt++;
        }
        freq[s[r]]++;
        r++;
        while(cnt>k){
            freq[s[l]]--;
            if(freq[s[l]] ==0){
                cnt--;
            }
            l++;
        }
        if(cnt ==k) ans = max(ans,r-l);
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends