class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i< nums.size();i++){
            int min_index = i;
            for(int j = i+1; j<nums.size();j++){
                if(nums[min_index] > nums[j]) min_index = j;
            }
            swap(nums[i],nums[min_index]);
        }
    }
};