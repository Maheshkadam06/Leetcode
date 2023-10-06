//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        int c =0;
        int btm = n;
        while(c < m){
            int up = -1;
            while(up+1 < btm){
                int mid =  up + (btm-up)/2;
                if(x <= matrix[mid][c]){
                    btm = mid;
                }
                else{
                    up = mid;
                }
            }
            // cout<<btm<<" "<<c<<endl;
            if(btm <n and matrix[btm][c] == x) return true;
            c++;
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends