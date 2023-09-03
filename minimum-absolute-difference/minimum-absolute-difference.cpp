class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int min_diff = INT_MAX;
        for(int i =1; i<arr.size();i++){
            min_diff = min(min_diff,arr[i]-arr[i-1]);
        }
        for(int i =1; i<arr.size();i++){
            if(min_diff == arr[i]-arr[i-1]){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};