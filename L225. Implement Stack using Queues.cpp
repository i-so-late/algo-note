#include "data_structures/structures.hpp"

class MyStack {
public:
    queue<int> In;
    queue<int> Out;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> &in = In.empty()? Out : In;
        in.emplace(x);
    }
    
    int pop() {
        queue<int> &in = In.empty()? Out : In;
        queue<int> &out = In.empty()?  In : Out;
        while(in.size()>1){
            out.emplace(in.front());
            in.pop();
        }
        int res = in.front();
        in.pop();
        return res;
    }
    
    int top() {
        queue<int> &in = In.empty()? Out : In;
        queue<int> &out = In.empty()?  In : Out;
        while(in.size()>1){
            out.emplace(in.front());
            in.pop();
        }
        int res = in.front();
        out.emplace(in.front());
        in.pop();
        return res;
    }
    
    bool empty() {
        return In.empty() && Out.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */