class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int cntu=0,cntd=0,cntr=0,cntl=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                cntu++;
            }
            else if(moves[i]=='D'){
                cntd++;
            }
            else if(moves[i]=='L'){
                cntl++;
            }else{
                cntr++;
            }
        }
        if(cntl!=cntr || cntu!=cntd){
            return false;
        }
        return true;
    }
};