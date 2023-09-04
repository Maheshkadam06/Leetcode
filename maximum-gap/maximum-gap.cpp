class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i = 0; i< nums.size();i++){
            mx = max(mx,nums[i]);
            mn = min(mn, nums[i]);
        }
        int k = 100000;
        double bucketsize = double((double)(mx-mn)/(double)k);
        // cout<<bucketsize<<endl;
        if(bucketsize<1) bucketsize =1.0;
        vector<vector<int>> buckets(k);
        for(int elmt : nums){
            // cout<<elmt<<" ";
            int index = (int)((double)(elmt-mn)/bucketsize);
            // cout<<elmt<<" "<<index<<" ";
            if(index == k) index = k-1;
            buckets[index].push_back(elmt);
        }
        for(auto b: buckets){
            sort(b.begin(),b.end());
        }
        int gp = 0;
        int last = INT_MAX;
        for(auto b: buckets){
            for(int i = 0; i < b.size();i++){
                gp = max(gp,b[i]-last);
                last = b[i];
            }

        }
        // int gp = 0;
        return gp;
    }
};