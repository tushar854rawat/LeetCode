class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto x : nums){
            m[x]++;
        }
        for(auto x : m){
            pq.push({x.second,x.first});
        }
        while(k-->0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};