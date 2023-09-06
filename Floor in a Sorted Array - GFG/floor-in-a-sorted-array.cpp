//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        // Your code here
        return bsearch(0,v.size()-1,v,x);
        
    }
    int bsearch(long long  l,long long r,vector<long long> &v, long long target){
        if(l<=r){
            long long mid = l + ((r-l)/2);
            if(v[mid] == target){
                return mid;
            }
            else if(v[mid] > target){
                return bsearch(l,mid-1,v,target);
            }
            else{
                return bsearch(mid+1,r,v,target);
            }
        }
        return r;
    }
    
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends