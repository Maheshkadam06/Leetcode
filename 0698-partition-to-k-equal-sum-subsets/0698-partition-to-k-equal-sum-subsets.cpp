class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum =0;
        for(int i = 0; i < nums.size();i++){
            sum += nums[i];
        }
        if(sum % k != 0) return false;
        int target = sum /k;
        vector<int> boxes(k,0);
        // sort(nums.begin(),nums.end());
        return solve(0,boxes,nums,k,target);
          
    }
    
    bool solve(int idx, vector<int> &boxes,vector<int> &nums, int k,int target){
        if(idx == nums.size()){
            for(int i = 0;i<k;i++){
                if(boxes[i] != target) return false;
            }
            return true;
        }
        
        for(int i = 0;i<min(k,idx+1);i++){
            if(boxes[i]+nums[idx] <=target){
                boxes[i]+= nums[idx];
                if(solve(idx+1,boxes,nums,k,target)) return true;
                boxes[i]-= nums[idx];
            }
        }
        return false;
    }
};