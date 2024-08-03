class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        if(n!=arr.size()){
            return false;
        }

        vector<int>c(1001);
        for(int i=0;i<n;i++){
            ++c[target[i]];
            --c[arr[i]];
        }
        for(int x : c){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
};