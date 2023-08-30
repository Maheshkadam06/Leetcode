class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt =0;
        vector<int> expected(heights.begin(),heights.end());
        for(int i = 0;i<expected.size();i++){
            bool nt_swp = true;
            for(int j =1;j<expected.size();j++){
                if(expected[j-1]>expected[j]){
                    swap(expected[j],expected[j-1]);
                    nt_swp= false;
                }
            }
            if(nt_swp) break;
        }
        for(int i =0; i< expected.size();i++){
            if(heights[i] != expected[i]) cnt++;
        }
        return cnt;
    }
};