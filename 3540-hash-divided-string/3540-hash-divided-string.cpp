class Solution {
public:
    string stringHash(string s, int k) {
        map<char,int>m;
        for(int i=0;i<26;i++){
            m['a'+i] = i;
        }
        string res = "";
        int n  = s.size();
        int a  = 0,sum =  0;
        for(int i=0;i<n;i++){
            char ch = s[i];
             if(m.find(ch)!=m.end()){
                sum+=m[ch];
            }
            a++;
            if(a==k){
                res += 'a'+sum%26;
                sum = 0;
                a = 0;
            }
        }
        if (a > 0) {
            res += 'a' + (sum % 26);
        }
        return res;
    }
};