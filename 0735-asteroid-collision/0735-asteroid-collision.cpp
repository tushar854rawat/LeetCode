class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        int n = ast.size();

        for(auto x : ast){
            if(x>0){
                st.push(x);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<-x){
                    st.pop();
                }

                if(st.empty() || st.top()<0){
                    st.push(x);
                }

                if(!st.empty() && st.top() == -x){
                    st.pop();
                }
            }
        }
        vector<int>res(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
};