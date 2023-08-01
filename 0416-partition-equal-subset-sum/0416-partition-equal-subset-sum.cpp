class Solution {
public:
    bool dp[201][20001];
    bool canPartition(vector<int>& nums) {
        memset(dp,true,sizeof(dp));
        int sum = 0;
        for(int i =0;i< nums.size();i++){
            sum += nums[i];
        }
        if(sum %2) return false;
        return equal(0,0,nums,sum);
    }
    bool equal(int idx, int sum1,vector<int> &nums, int sum){
        if(idx == nums.size()){
            if(sum1 == sum/2){return true;}
            return false;
        }
        if(dp[idx][sum1]!= true) return dp[idx][sum1];
        if(equal(idx+1,sum1+nums[idx],nums,sum)) return true;
        if(equal(idx+1,sum1,nums,sum)) return true;
        return dp[idx][sum1] = false;
    }
};