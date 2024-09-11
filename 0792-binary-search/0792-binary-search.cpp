class Solution {
public:
    int binary(vector<int>& nums, int t, int l, int h) {
        if (l > h) { 
            return -1;
        }
        
        int mid = l + (h - l) / 2;
        if (nums[mid] == t) {
            return mid;
        }
        if (nums[mid] < t) {
            return binary(nums, t, mid + 1, h);  
        } else {
            return binary(nums, t, l, mid - 1);  
        }
    }
    
    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size() - 1);
    }
};
