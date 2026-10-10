#include "data_structures/structures.hpp"

struct MyTreeNode
{
    MyTreeNode* tn[26] = {};
    bool isString = false;
    ~MyTreeNode(){
        for(MyTreeNode* p : tn){
            delete p;
        }
    }
};


class Trie {
public:
    MyTreeNode* root;
    Trie() {
        root = new MyTreeNode();
    }
    
    void insert(string word) {
        MyTreeNode* cur = root;
        for(int i=0; i<word.size(); ++i){
            if(cur->tn[word[i]-'a'] == nullptr){
                cur->tn[word[i]-'a'] = new MyTreeNode();
            }
            cur = cur->tn[word[i]-'a'];
        }
        cur->isString = true;
        return;
    }
    
    bool search(string word) {
        MyTreeNode* cur = root;
        for(int i=0; i<word.size(); ++i){
            if(cur->tn[word[i]-'a'] == nullptr){
                return false;
            }
            cur = cur->tn[word[i]-'a'];
        }
        if(cur->isString == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        MyTreeNode* cur = root;
        for(int i=0; i<prefix.size(); ++i){
            if(cur->tn[prefix[i]-'a'] == nullptr){
                return false;
            }
            cur = cur->tn[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */