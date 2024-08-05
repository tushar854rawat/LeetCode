class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int sum = 1,curr = nums[0];
        for(int i=1;i<n;i++){
            if(curr==nums[i]){
                sum++;
            }
            if(curr!=nums[i]){
                sum--;
            }
            if(sum==0){
                curr=nums[i];
                sum = 1;
            }
        }
        return curr;
    }
};