class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> index;
        for(int i =0;i<nums.size();i++){
            index[nums[i]] = i;
        }
        for(int i =0;i<nums.size();i++){
            if(index.find(target-nums[i]) != index.end() and index[target-nums[i]]!=i){
                return{index[target-nums[i]],i};
            }
        }
        return{};
    }
};