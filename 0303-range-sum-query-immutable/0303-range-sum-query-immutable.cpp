class NumArray {
private:
    std::vector<int>prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i=0;i<n;i++){
            c += nums[i];
            prefix.push_back(c);
        }
    }
    
    int sumRange(int left, int right) {
        int r = prefix[right];
        int l = (left > 0)?prefix[left-1]:0;
        return r-l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */