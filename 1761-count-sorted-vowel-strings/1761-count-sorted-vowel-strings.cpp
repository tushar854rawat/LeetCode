class Solution {
public:
    void f(int n,int ind,vector<char>& a,vector<string>& ans,string& s){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        
        for(int i=ind;i<a.size();i++){
            s+=a[i];
            f(n,i,a,ans,s);
            s.pop_back();
        }
    }
    int countVowelStrings(int n) {
        vector<char>s = {'a','e','i','o','u'};
        vector<string>ans;
        string res = "";
        f(n,0,s,ans,res);
        return ans.size();
    }
};