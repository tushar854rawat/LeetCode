class Solution {
public:
    static bool compare(string &a,string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>s;
        for(auto x : nums){
            s.push_back(to_string(x));
        }

        sort(s.begin(),s.end(), compare);

        string res = "";
        for(auto x : s){
            res+=x;
        }
        if(res[0]=='0'){
            return "0";
        }
        return res;
    }
};