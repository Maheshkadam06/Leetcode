class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
//         concept of heapsort
        int n = nums.size();
//         heapified
        for(int i = nums.size();i>=0;i--){
            heapify(nums,n,i);
        }
        
        for(int i = n-1; i>=0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
        return nums;
    }
    
    
    
    
    void heapify(vector<int> &nums, int sz, int index){
        int left =2*index+1;
        int right = 2*index+2;
        int largest = index;
        if(left<sz and nums[left] > nums[largest]){
            largest = left;
        }
        if(right<sz and nums[right] > nums[largest]){
            largest = right;
        }
        if(index != largest){
            swap(nums[index], nums[largest]);
            heapify(nums,sz,largest);
        }
    }
};