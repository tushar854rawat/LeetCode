class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> set;
        int m = 101;

        for (int i = 0; i < nums.size(); i++) {
            m = min(m, nums[i]);
            set.insert(nums[i]);
        }
        
        if(m < k) return -1;
        return set.size() + (m == k ? -1 : 0);
    }
};