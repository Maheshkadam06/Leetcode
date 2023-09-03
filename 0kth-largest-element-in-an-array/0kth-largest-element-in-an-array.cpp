class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//         minheapify
        nums.push_back(INT_MIN);
        for(int i = k; i>=0;i--){
            minheapify(nums,k,i);
        }
        // for(int i = k; i>=0;i--){
        //     cout<<nums[i]<<" ";
        // }
        for(int i = nums.size()-2;i>k;i--){
            swap(nums[0],nums[i]);
            minheapify(nums,k,0);
        }
        nums[0] = INT_MAX;
        minheapify(nums,k,0);
        return nums[0];
        
        
    }
    void minheapify(vector<int>& nums, int maxidx,int idx){
        int left = 2*idx+1;
        int right = 2*idx+2;
        
        int smallest = idx;
        if(left <= maxidx and nums[smallest] > nums[left]){
            smallest = left;
        }
        if(right <= maxidx and nums[smallest] > nums[right]){
            smallest = right;
        }
        if(idx != smallest){
            swap(nums[smallest],nums[idx]);
            minheapify(nums,maxidx,smallest);
        }
    }
};