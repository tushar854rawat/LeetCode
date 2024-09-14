class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = height.size();
        vector<int>v;

        for(int i= 1;i<n;i++){
            if(height[i-1]>threshold){
                v.push_back(i);
            }
        }
        return v;
    }
};