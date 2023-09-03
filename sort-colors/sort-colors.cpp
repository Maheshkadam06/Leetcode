class Solution {
public:
    void sortColors(vector<int>& nums) {
        int col[3] ={0};
        for(int i: nums) col[i]++;
        int j =0;
        for(int i =0; i<3;i++){
            while(col[i]){
                nums[j] = i;
                j++;
                col[i]--;
            }
        }
    }
};