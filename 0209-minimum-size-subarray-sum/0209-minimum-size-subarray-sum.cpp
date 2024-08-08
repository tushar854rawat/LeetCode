class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0,sum = 0,minlength=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                minlength = min(minlength,i-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return (minlength==INT_MAX)?0:minlength;
    }
};