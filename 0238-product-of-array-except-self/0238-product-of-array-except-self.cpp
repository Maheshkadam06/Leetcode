class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size()+2,1);
        for(int i = nums.size();i>=1;i--){
            ans[i] = ans[i+1]*nums[i-1];
        }
        int prod = 1;
        for(int i = 1;i<nums.size()+1;i++){            
            ans[i] = prod*ans[i+1];
            prod = prod*nums[i-1];
        }
        vector<int> ans2(ans.begin()+1,ans.end()-1);
        return ans2;
    }
};