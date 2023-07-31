class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int rep;
        for( rep= nums.size()-2;rep>=0;rep--){
            if(nums[rep]<nums[rep+1]){
                break;
            }
        }
        if(rep >=0){
            int i;
            for(i = nums.size()-1;i>rep;i--){
                if(nums[i]>nums[rep]){
                    break;
                }
            }
            int temp = nums[i];
            nums[i] = nums[rep];
            nums[rep] = temp;
        }
        
        sort(nums.begin()+rep+1,nums.end());
        return;
    }
};