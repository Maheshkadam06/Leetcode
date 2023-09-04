class Solution {
public:
    int maximumGap(vector<int>& nums) {
//     by radix sort
        int mx = 0;
        for(int i : nums){
            mx = max(mx,i);
        }
        int dec = 1;
        vector<int> numscopy(nums.begin(),nums.end());
        while(mx >= dec){
            countingsort(numscopy,dec);
            dec *= 10;
        }
        int gp = 0;
        for(int i = 1; i< nums.size();i++){
            gp = max(gp,numscopy[i]-numscopy[i-1]);
            // cout<<nums[i]<<" ";
        }
        return gp;
    }
    
    void countingsort(vector<int> &nums,int dec){
        int count[10] = {0};
        for(int elmt : nums){
            int dec_place = elmt/dec;
            // cout<<dec_place<<" ";
            count[dec_place%10]++;
        }
        // starting index
        int carry = count[0];
        count[0] = 0;
        for(int i = 1; i < 10;i++){
            int temp = count[i];
            count[i] = count[i-1]+carry;
            carry = temp;
        }
        // return;/
        vector<int> unsorted(nums.begin(),nums.end());
        for(int elmt : unsorted){
            int dec_place = elmt/dec;
            nums[count[dec_place%10]] = elmt;
            count[dec_place%(10)]++;
            
        }
    }
    
};