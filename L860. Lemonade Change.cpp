#include "data_structures/structures.hpp"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int d5 =0;
        int d10 = 0;
        for(int i=0; i<bills.size(); ++i){
            if(bills[i]==5){
                d5++;
            }
            else if(bills[i]==10){
                d10++;
                d5--;
                if(d5<0) return false;
            }else{
                if(d10 && d5){
                    d10--; d5--;
                    continue;
                }else if(d5>=3){
                    d5 -= 3;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};