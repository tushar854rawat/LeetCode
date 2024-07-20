class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int last = 0;

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[last++] = nums[i];
            }
        }

        for(int i=last;i<n;i++){
            nums[i]=0;
        }
    }
};