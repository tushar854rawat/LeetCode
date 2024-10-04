class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total_sum = 0;
        for (int x : nums) {
            total_sum = (total_sum + x) % p;
        }

        if (total_sum == 0) {
            return 0; // If the total sum is already divisible by p
        }

        unordered_map<int, int> mod_map;
        mod_map[0] = -1; // To handle subarray starting from index 0
        int prefix_sum = 0, min_len = n;
        for (int i = 0; i < n; i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - total_sum + p) % p;

            if (mod_map.find(target) != mod_map.end()) {
                min_len = min(min_len, i - mod_map[target]);
            }

            mod_map[prefix_sum] = i;
        }

        return (min_len == n) ? -1 : min_len;
    }
};
