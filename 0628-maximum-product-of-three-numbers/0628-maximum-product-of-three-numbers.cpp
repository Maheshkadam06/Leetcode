class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int prdt1 = nums[n-1]*nums[n-2]*nums[n-3];
        int prdt2 = nums[0]*nums[1]*nums[n-1];
        
        return max(prdt1,prdt2);
    }
};