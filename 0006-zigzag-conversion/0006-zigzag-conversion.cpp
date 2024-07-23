class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<string> v(numRows);
        bool dir = true;
        int j =0;
        if(numRows == 1) return s;
        for(int i=0;i<n;i++)
        {
            v[j] += s[i];
            if(dir) j++;
            else j--;
            if(j == numRows) j = numRows-2, dir = false;
            if(j<0) j =1, dir = true; 
        }
        string res;
        for(int i=0;i<v.size();i++)
        {
            res+= v[i];
        }
        return res;
    }
};