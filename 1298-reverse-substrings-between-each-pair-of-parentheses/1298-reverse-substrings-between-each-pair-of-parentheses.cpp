class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string ans = "";
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int j=0;j<ans.size();j++){
                    st.push(ans[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        string res = "";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};