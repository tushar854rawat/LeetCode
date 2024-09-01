class Solution {
public:
    bool checkTwoChessboards(string one, string two) {
         int ch1=one[0]-'a';
         int ch2=one[1]-'1';
         int ch3=two[0]-'a';
         int ch4=two[1]-'1';
         if((ch1+ch2)%2==(ch3+ch4)%2)return true;
         return false;
        
    }
};