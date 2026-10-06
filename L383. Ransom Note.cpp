#include "data_structures/structures.hpp"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rec[26] = {0};
        for(int i=0; i<ransomNote.size(); i++){
            rec[ransomNote[i]-'a']++;
        }
        for(int j=0; j<magazine.size(); j++){
            rec[magazine[j]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(rec[i]>0) return false;
        }
        return true;
    }
};