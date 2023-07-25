class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // kadane 
        int curr = 0;
        int high = 0;
        int occur[256];
        memset(occur,-1,sizeof(occur));
        for(int i = 0; i< s.size();i++){
            curr = min(curr+1,i-occur[s[i]]);
            occur[s[i]] = i;
            high = max(high,curr);
        }
        return high;
    }
};