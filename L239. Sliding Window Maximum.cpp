#include "data_structures/structures.hpp"

class Solution {
public:
    class myQueue{
        deque<int> que;
    public:
        void pop(int a){
            if(!que.empty() && que.front()==a) que.pop_front();
        }
        void push(int a){
            while(!que.empty() && que.back() < a){
                que.pop_back();
            }
            que.push_back(a);
        }
        int front(){
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myQueue que;
        for(int i=0; i<k; i++){
            que.push(nums[i]);
        }
        vector<int> res;
        res.push_back(que.front());
        for(int i=k; i<nums.size(); ++i){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};