class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int l = 0,r = height.size()-1,ml = 0,mr = 0;

        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=ml){
                    ml = height[l];
                }
                else{
                    area += ml-height[l];
                }
                l++;
            }
            else{
                if(height[r]>=mr){
                    mr = height[r];
                }
                else{
                    area += mr-height[r];
                }
                r--;
            }
        }
        return area;
    }
};