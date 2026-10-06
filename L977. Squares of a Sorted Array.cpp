#include "data_structures/structures.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int tail = nums.size() - 1;
        int head = 0;
        int k = tail;
        while(head <= tail){
            if(nums[head] * nums[head] < nums[tail]*nums[tail]){
                res[k] = nums[tail]*nums[tail];
                tail--;
            }else{
                res[k] = nums[head] * nums[head];
                head++;
            }
            k--;
        }
        return res;
    }
};