class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<std::string,int>m;
        std::vector<std::string>v;
        for(const auto& x : arr){
            m[x]++;
        }
        for(const auto& x : arr){
            if(m[x]==1){
                v.push_back(x);
            }
        }
        if(v.size()>=k){
            return v[k-1];
        }
        return "";
    }
};