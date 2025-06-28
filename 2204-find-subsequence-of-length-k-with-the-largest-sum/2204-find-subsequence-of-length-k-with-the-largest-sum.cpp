class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); ++i) {
            indexed_nums.emplace_back(nums[i], i);
        }

        sort(indexed_nums.begin(), indexed_nums.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        indexed_nums.resize(k);

        sort(indexed_nums.begin(), indexed_nums.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (auto &[val, idx] : indexed_nums) {
            result.push_back(val);
        }

        return result;
    }
};
