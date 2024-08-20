class Solution {
public:
    void f(int ind,string map[],vector<string>&ans,string output,string digit){
        if(ind>=digit.size()){
            ans.push_back(output);
            return;
        }

        int num = digit[ind]-'0';
        string res = map[num];

        for(int i=0;i<res.size();i++){
            output.push_back(res[i]);
            f(ind+1,map,ans,output,digit);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string>ans;
        string output = "";

        string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,map,ans,output,digits);
        return ans;
    }
};