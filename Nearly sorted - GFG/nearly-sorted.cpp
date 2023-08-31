//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        // insertion sort
        vector<int> ans;
        // for(int i = 0; i< num;i++){
        //     ans.push_back(arr[i]);
        //     int j = i;
        //     while(j>0 and ans[j]<ans[j-1]){
        //         swap(ans[j],ans[j-1]);
        //         j--;
        //     }
        // }
        //  not working
        priority_queue<int,vector<int>,greater<int>> pq;
        // min heap 
        for(int i =0; i<= k and i<num;i++) pq.push(arr[i]);
        
        for(int i =0;i<num;i++){
            ans.push_back(pq.top());
            pq.pop();
            if(i+k+1 <num)pq.push(arr[i+k+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends