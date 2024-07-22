class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        map<int,string>m;

        for(int i=0;i<n;i++){
            m[heights[i]]=names[i];
        }
        vector<string>v;
        for(auto x : m){
            v.push_back(x.second);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};