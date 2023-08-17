//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code 
        //  make adj list 
        // const int NUM = 31; no need
        int indgr[K] = {0};
        vector<vector<int>> adj(K, vector<int>());
        for(int  i =1; i<N;i++){
            int a = dict[i-1].size();
            int b = dict[i].size();
            int j;
            // cout<<dict[i-1].size()-1<<ebdl;
            for(j = 0; j < min(a,b);j++){
                if(dict[i-1][j] != dict[i][j]){
                    // cout<<dict[i-1][j]<<dict[i][j]<<endl;
                    break;
                }
            }
            if(j != min(a,b)){
                adj[int(dict[i-1][j])-97].push_back(int(dict[i][j])-97);
                indgr[int(dict[i][j])-97]++;
                // cout<<adj[int(dict[i-1][j])-97][adj[int(dict[i-1][j])-97].size()-1]<<endl;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < K;i++){
            // indgr[i] = adj[i].size(); wrong indgr in different
            // cout<<indgr[i]<<" ";
            if(indgr[i] == 0) q.push(i);
        }
        
        string topo = "";
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(char(node+97));
            
            for(auto it: adj[node]){
                indgr[it]--;
                // cout<<indgr[it]<<endl;
                if(indgr[it] == 0) q.push(it);
            }
        }
        // cout<<topo.size()<<endl;
        return topo;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends