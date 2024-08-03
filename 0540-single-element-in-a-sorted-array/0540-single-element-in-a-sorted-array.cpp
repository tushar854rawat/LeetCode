class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int c = 0;
        for(auto x : nums){
            c^=x;
        }
        return c;
    }
};