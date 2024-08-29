class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> sortedList;

        for (int i = n - 1; i >= 0; --i) {
            int left = 0, right = sortedList.size();
            // Perform binary search to find the first index where nums[i] should go
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sortedList[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            ans[i] = left; // number of elements smaller than nums[i]
            sortedList.insert(sortedList.begin() + left, nums[i]);
        }

        return ans;
    }
};
