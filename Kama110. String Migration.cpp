#include "data_structures/structures.hpp"

struct AdjNode
{
    string val;
    AdjNode* next;
    AdjNode(string s){this->val = s; next = nullptr;}
};


class Solution{
public:
    unordered_map<string, AdjNode*> um;

    bool isPath(string s1, string s2){
        if(s1.size()!=s2.size()) return false;
        int diff = 0;
        for(int i=0; i<s1.size(); ++i){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        return diff==1;
    }
    void buildAdjList(vector<string> strs){
        for(int i=0; i<strs.size()-1; ++i){
            for(int j=i+1; j<strs.size(); ++j){
                if(isPath(strs[i], strs[j])){
                    if(um.count(strs[i]) == 0){
                        um[strs[i]] = new AdjNode(strs[j]);
                    }else{
                        AdjNode* tmp = um[strs[i]];
                        while(tmp->next) tmp = tmp->next;
                        tmp->next = new AdjNode(strs[j]);
                    }
                    if(um.count(strs[j]) == 0){
                        um[strs[j]] = new AdjNode(strs[i]);
                    }else{
                        AdjNode* tmp = um[strs[j]];
                        while(tmp->next) tmp = tmp->next;
                        tmp->next = new AdjNode(strs[i]);
                    }
                }
            }
        }
    }

    int bfs(const vector<string>& strs, string beginStr, string endStr){
        queue<string> que;
        unordered_set<string> us;
        que.push(beginStr);
        us.emplace(beginStr);
        int res = 1;
        while(!que.empty()){
            int n = que.size();
            res++;
            while(n){
                string cur = que.front();
                que.pop();
                AdjNode* tmp = um[cur];
                while(tmp){
                    if(us.find(tmp->val)==us.end()){
                        que.push(tmp->val);
                        us.emplace(tmp->val);
                        if(tmp->val == endStr) return res;
                    }
                    tmp = tmp->next;
                }
                n--;
            }
        }
        return 0;
    }

    int stringMigration(const vector<string>& strs, string beginStr, string endStr){    
        vector<string> tmp(strs.begin(), strs.end());
        tmp.push_back(beginStr); tmp.push_back(endStr);
        buildAdjList(tmp);
        return bfs(strs, beginStr, endStr);
    }
};


int main(){
    int n;
    string beginStr, endStr;
    cin >> n;
    cin >> beginStr >> endStr;
    vector<string> strs;
    for(int i=0; i<n; ++i){
        string tmp;
        cin>>tmp;
        strs.push_back(tmp);
    }
    Solution s;
    cout << s.stringMigration(strs, beginStr, endStr) << endl;
    return 0;
}