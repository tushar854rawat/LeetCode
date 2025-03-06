class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>m;
        for(auto x : grid){
            for(auto a : x){
                m[a]++;
            }
        }
        int repeat = 0;
        for(auto x : m){
            if(x.second>1){
                repeat = x.first;
            }
        }
        int missing = 0;
        int n = m.size();
        for(int i=1;i<=n*n;i++){
            if(m.find(i)!=m.end()){
                continue;
            }
            else{
                missing = i;
                break;
            }
        }
        return {repeat,missing};
    }
};