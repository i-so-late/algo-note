#include "data_structures/structures.hpp"

class LRUCache {
    struct DeNode{
        int key, val;
        DeNode* next;
        DeNode* prev;
        DeNode(int k, int v):key(k), val(v), next(NULL), prev(NULL){}
    };

    unordered_map<int, DeNode*> mp;
    DeNode* head;
    DeNode* tail;
    int cap;

    void moveToHead(DeNode* n){
        if(n->next && n->prev){
            DeNode* nnxt = n->next;
            DeNode* nprev = n->prev;
            nnxt->prev = nprev;
            nprev->next = nnxt;
        }
        n->next = head->next;
        head->next->prev = n;
        n->prev = head;
        head->next = n;
    }

    void removeFromTail(){
        DeNode* n = tail->prev;
        int k = n->key;
        mp.erase(k);
        tail->prev = n->prev;
        n->prev->next = tail;
        delete n;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new DeNode(-1, -1);
        tail = new DeNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache() { for(DeNode* x = head; x; ){ auto nx = x->next; delete x; x = nx; } }

    int get(int key) {
        if(mp.count(key)==0) return -1;
        DeNode* n = mp[key];
        moveToHead(n);
        return n->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it!=mp.end()){
            DeNode* n = it->second;
            n->val = value;
            moveToHead(n);
        }else{
            DeNode* n = new DeNode(key, value);
            mp[key] = n;
            moveToHead(n);
            if(mp.size() > cap){
                removeFromTail();
            }
        }
    }
};