class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size  = bills.size();
        int count_five = 0 , count_ten = 0;
        
        for(int i =0 ; i < size; i++){
            count_five +=(bills[i] == 5);

            if(bills[i] == 10){
                if(!count_five) return false;
                count_five--;
                count_ten++;
            }
            if(bills[i] == 20){
                if(count_five >= 1 && count_ten >= 1){
                    count_five--;
                    count_ten--;
                }
                else if(count_five >= 3){
                    count_five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};