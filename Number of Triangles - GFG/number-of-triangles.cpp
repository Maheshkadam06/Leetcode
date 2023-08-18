//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int numberOfTriangles(vector<vector<int>> &g,int n)
        {
            // code it up
            int cnt = 0;
            for(int i = 0; i< n;i++){
                for(int j = 0; j< n;j++){
                    if(i == j) continue;
                    for(int k = 0; k< n;k++){
                        if(k == i or k == j) continue;
                        if(g[i][j]==1 and g[j][k]==1 and g[k][i]==1) cnt++;
                    }
                }
            }
            return cnt/3;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n,vector<int> (n));
        for(auto &j:g)
            for(auto &i:j)
                cin>>i;
        Solution s;
        cout<<s.numberOfTriangles(g,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends