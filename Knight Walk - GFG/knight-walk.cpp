//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int vis[1000][1000];
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	   // BFS;
	   memset(vis,0,sizeof(vis));
	   
	   int delX[8] = {2,2,-2,-2,1,1,-1,-1};
	   int delY[8] = {1,-1,1,-1,2,-2,2,-2};
	   
	   queue<pair<pair<int,int>,int>> q;
	   // {{x,y},move}
	   
	   q.push({{KnightPos[0]-1,KnightPos[1]-1},0});
	   vis[KnightPos[0]-1][KnightPos[1]-1] =1;
	   
	   while(!q.empty()){
	       int row = q.front().first.first;
	       int col = q.front().first.second;
	       int move = q.front().second;
	       q.pop();
	       
	       if(row == TargetPos[0]-1 and col == TargetPos[1]-1){
               return move;
           }
	       
	       for(int i= 0;i<8;i++){
	           int x = row + delX[i];
	           int y = col + delY[i];
	
	           bool fit = x >=0 and x < N and y >=0 and y < N;
	           
	                      
	           if(fit and !vis[x][y]){
	               q.push({{x,y},move+1});
	               vis[x][y] = 1;
	           }
	       }
	   }
	   
	   

	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends