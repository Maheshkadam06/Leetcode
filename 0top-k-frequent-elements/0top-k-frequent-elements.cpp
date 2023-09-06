class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int freq[10000+10000+1] ={0};
        for(int i: nums){
            freq[i+10000]++;
        }
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i<10000+1000+1;i++){
            if(freq[i]){
                pq.push({freq[i],i-10000});
                if(pq.size() > k) pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size() != 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};