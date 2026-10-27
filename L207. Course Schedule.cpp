#include "data_structures/structures.hpp"

class Solution {
public:
    bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<list<int>> map(numCourses);
        vector<int> reff(numCourses, 0);
        for(int i=0; i<prerequisites.size(); ++i){
            map[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
            reff[prerequisites[i][0]]++;
        }
        queue<int> que;
        for(int i=0; i<reff.size(); ++i){
            if(reff[i] == 0) que.push(i);
        }
        int cnt = 0;
        while(!que.empty()){
            int tmp = que.front();
            que.pop();
            cnt++;
            for(int p: map[tmp]){
                reff[p]--;
                if(reff[p] == 0) que.push(p);
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};

int main(){
    Solution s;
    s.canFinish(2, {{0,1}});
}