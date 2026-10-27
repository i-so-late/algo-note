#include "data_structures/structures.hpp"

struct Password
{
    /* data */
    string s;
    int g, f;
    Password(string _s, int _g, int _f): s(_s), g(_g), f(_f){}
    bool operator<(const Password& p) const { return this->f > p.f; }
};


class Solution {
    int dirction[2] = {1, -1};
public:
    int heuristic(string s, string target){
        int dis = 0;
        for(int i=0; i<s.size(); ++i){
            dis += min(((s[i]-'0') + 10 - (target[i]-'0'))%10, ((target[i]-'0') + 10 - (s[i]-'0'))%10);
        }
        return dis;
    }

    int Astar(vector<string>& deadends, string target){
        priority_queue<Password> pq;
        pq.push({"0000", 0, heuristic("0000", target)});
        unordered_map<string, int> um;
        unordered_set<string> ddends(deadends.begin(), deadends.end());
        if(ddends.find("0000")!=ddends.end()) return -1;
        um["0000"] = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            for(int i=0; i<4; ++i){
                for(int j=0; j<2; ++j){
                    string tmps = cur.s;
                    int tmpg = cur.g;
                    tmps[i] = (tmps[i]-'0' + dirction[j] + 10) % 10 +'0';
                    if(ddends.find(tmps)!=ddends.end()) continue;
                    if(tmps == target) return tmpg+1;
                    if(um.find(tmps)!=um.end() && um[tmps] <= tmpg+1) continue;
                    else um[tmps] = tmpg+1;
                    pq.push({tmps, tmpg+1, tmpg+1+heuristic(tmps, target)});
                }
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        return Astar(deadends, target);
    }
};