class Solution {
public:
    int f(int ind, int sum, vector<int>& arr, int target) {
        if (ind == arr.size()) {
            return (sum == target) ? 1 : 0;
        }
        int add = f(ind + 1, sum + arr[ind], arr, target);
        int subtract = f(ind + 1, sum - arr[ind], arr, target);
        return add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0, 0, nums, target);
    }
};
