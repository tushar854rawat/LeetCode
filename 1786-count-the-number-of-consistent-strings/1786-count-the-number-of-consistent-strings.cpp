class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char>s;
    int count=0;
    for(auto x:allowed)
    s.insert(x);
    for(auto word:words){
            int check=1;
        for(int i=0;i<word.size();i++){
            if (s.find(word[i]) == s.end()){
                check=-1;
                break;
            }
        }
        if(check == 1) count++;
    }
    return count;
    }
};