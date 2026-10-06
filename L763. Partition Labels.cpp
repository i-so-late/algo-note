#include "data_structures/structures.hpp"

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> getRange(string& s){
        vector<vector<int>> res;
        for(char c = 'a'; c <='z'; ++c){
            int leftR = -1;
            int rightR = -1;
            int i = 0;
            while(i<s.length()){
                if(s[i] == c){
                    if(leftR == -1){
                        leftR = i;
                        rightR = i;
                    }else{
                        rightR = i;
                    }
                }
                ++i;
            }
            if(leftR != -1) res.push_back({leftR, rightR});
        }
        return res;
    }
    vector<int> partitionLabels(string s) {
        vector<vector<int>> tmp = getRange(s);
        sort(tmp.begin(), tmp.end(), cmp);
        vector<int> res;
        int leftR = tmp[0][0];
        int rightR = tmp[0][1];
        for(int i=1; i<tmp.size(); ++i){
            if(tmp[i][0]>rightR){
                res.push_back(rightR-leftR+1);
                leftR = tmp[i][0];
                rightR = tmp[i][1];
            }else{
                rightR = max(rightR, tmp[i][1]);
            }
        }
        res.push_back(rightR-leftR+1);
        return res;
    }
};