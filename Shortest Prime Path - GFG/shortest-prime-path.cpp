//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool prime[10000];
    
    void sieve(){
        memset(prime,true,sizeof(prime));
        prime[1] =0;
        prime[0] = 0;
        for(int i = 2; i*i<10000;i++){
            for(int j = i*i; j< 10000;j+=i){
                prime[j]= false;
            }
        }
    }
    int solve(int Num1,int Num2)
    {   
      //code here
      sieve();
      for(int i = 2; i<=999;i+=1){
          prime[i] = false;
      }
      int vis[10000];
      memset(vis,-1,sizeof(vis));
      queue<int> q;
      q.push(Num1);
      vis[Num1] = 0;
      while(!q.empty()){
          int curr = q.front();
          if(curr == Num2) return vis[Num2];
          q.pop();
        //   case1;
        for(int i = 10; i <=10000;i*=10){
            int temp = curr/i;
            int rem = curr%(i/10);
            for(int j  = 0; j <10;j++){
                int node = (temp*i+j*(i/10)+rem);
                if(prime[node] and vis[node]==-1){
                    vis[node] = vis[curr] +1;
                    q.push(node);
                }
            }
        }
        
      }
      return 0;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends