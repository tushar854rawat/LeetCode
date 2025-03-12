class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int pos = 0,neg = 0;
        for(auto x : nums){
            if(x < 0){
                neg++;
            }
            else if(x > 0){
                pos++;
            }
            
        }

        return max(pos,neg);
    }
};