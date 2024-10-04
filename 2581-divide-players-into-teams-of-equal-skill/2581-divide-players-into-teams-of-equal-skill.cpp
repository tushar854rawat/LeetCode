class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        long long  n = nums.size();
        sort(nums.begin(),nums.end());
        long long i = 0,j = n-1,sum = 0;
        long long expected_sum = nums[i]+nums[j];
        while(i<j){
            if((nums[i]+nums[j])!=expected_sum){
                return -1;
            }
            sum += (nums[i]*nums[j]);
            i++;j--;
        }
        return sum;
    }
};