class Solution {
public:
    int dp[2500][2501];
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return lcs(0,2500,nums);
    }
    int lcs(int i,int j,vector<int> &nums){
        if(i == nums.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if( j == 2500 or nums[i]>nums[j]){
            return dp[i][j]=  max(lcs(i+1,i,nums)+1,lcs(i+1,j,nums));
        }
        return dp[i][j] = lcs(i+1,j,nums);
    }
};