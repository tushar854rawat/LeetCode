class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        while(k>0){
            int mini = INT_MAX;
            int ind = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<mini){
                    mini = nums[i];
                    ind = i;
                }
            }
            int a = nums[ind]*mul;
            nums[ind]=a;
            k--;
        }
        return nums;
    }
};