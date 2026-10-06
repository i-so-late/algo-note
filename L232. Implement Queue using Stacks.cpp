#include "data_structures/structures.hpp"

class MyQueue {
public:
    stack<int> In;
    stack<int> Out;
    MyQueue() {
        
    }
    
    void push(int x) {
        In.push(x);
    }
    
    int pop() {
        while(!In.empty()){
            Out.push(In.top());
            In.pop();
        }
        int tmp = Out.top();
        Out.pop();
        while(!Out.empty()){
            In.push(Out.top());
            Out.pop();
        }
        return tmp;
    }
    
    int peek() {
        while(!In.empty()){
            Out.push(In.top());
            In.pop();
        }
        int tmp = Out.top();
        while(!Out.empty()){
            In.push(Out.top());
            Out.pop();
        }
        return tmp;
    }
    
    bool empty() {
        return In.empty();
    }
};