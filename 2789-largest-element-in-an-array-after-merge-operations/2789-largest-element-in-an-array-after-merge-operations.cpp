class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long curr = 0;
        long long mx = INT_MIN;
        
        for(int i = nums.size()-1; i>= 0; i--){
            if(nums[i] > curr){
                curr = nums[i];
            }
            else{
                curr += nums[i];
            }
            mx = max(curr, mx);
        }
        return mx;
    }
};