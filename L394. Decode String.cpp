#include "data_structures/structures.hpp"

class Solution {
public:
    string decodeString(string s) {
        stack<string> stt;
        stack<int> sti;
        int num = 0;
        string cur = "";
        for(int i=0; i<s.size();++i){
            if(s[i]>='0' && s[i]<='9'){
                num = num*10 + s[i]-'0';
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                cur += s[i];
            }else if(s[i] == ']'){
                int n = sti.top(); sti.pop();
                string ss = stt.top(); stt.pop();
                while(n--) ss += cur;
                cur = ss;
            }else{
                sti.push(num);
                stt.push(cur);
                cur.clear();
                num = 0;
            }
        }
        return cur;
    }
};