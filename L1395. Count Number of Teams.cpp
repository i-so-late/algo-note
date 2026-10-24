#include "data_structures/structures.hpp"

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int Lless=0, Lgreater = 0;
        int Rless = 0, Rgreater = 0;
        int res = 0;
        for(int j=1; j<rating.size()-1; ++j){
            for(int i=j-1; i>=0; --i){
                if(rating[i]>rating[j]) Lgreater++;
                else if(rating[i] < rating[j]) Lless++;
            }
            for(int k = j+1; k<rating.size(); ++k){
                if(rating[k]>rating[j]) Rgreater++;
                else if(rating[k]<rating[j]) Rless++;
            }
            res += Lless*Rgreater + Rless*Lgreater;
            Lless = Lgreater = Rgreater = Rless = 0;
        }
        return res;
    }
};