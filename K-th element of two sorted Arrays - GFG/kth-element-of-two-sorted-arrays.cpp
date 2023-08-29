//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int j = 0;
        
        int cnt =0;
        int curr =0;
        while(cnt!=k and i<n and j<m){
            if(arr1[i]>arr2[j]){
                curr = arr2[j];
                j++;
                
            }
            else{
                curr = arr1[i];
                i++;
            }
            cnt++;
        }
        while(cnt !=k and i<n){
            curr = arr1[i];
            i++;
            cnt++;
        }
        while(cnt !=k and j<m){
            curr = arr2[j];
            j++;
            cnt++;
        }
        return curr;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends