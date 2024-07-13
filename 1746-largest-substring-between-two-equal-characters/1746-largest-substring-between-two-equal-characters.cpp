class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char,int>m;
        int t = -1;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(m.find(c)!=m.end()){
                t = max(t,i-m[c]-1);
            }
            else{
                m[c]=i;
            }
        }
        return t;
    }
};