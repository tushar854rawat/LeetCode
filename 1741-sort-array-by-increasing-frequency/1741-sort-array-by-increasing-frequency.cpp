class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;

        for(auto x : nums){
            m[x]++;
        }

        vector<pair<int,int>> v;
        for(auto x : m){
            v.push_back(x);
        }

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if(a.second == b.second){
                return a.first > b.first; // Sort by value in descending order if frequencies are the same
            }
            return a.second < b.second; // Sort by frequency in ascending order
        });

        vector<int> ans;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].second; j++){
                ans.push_back(v[i].first);
            }
        }

        return ans;
    }
};
