class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        unordered_map<string,int>m1,m2;
        int len = n/k;
        for(int i=0;i<n;i += len){
            string x = s.substr(i,len);
            m1[x]++;
        }        for(int i=0;i<n;i += len){
            string x = t.substr(i,len);
            m2[x]++;
        }
        return m1==m2;
    }
};