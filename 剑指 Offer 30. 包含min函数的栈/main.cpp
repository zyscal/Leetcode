#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    stack<int> minstack;
    stack<int> ansstack;
    MinStack() {
        while (!minstack.empty())
        {
            minstack.pop();
        }
        while (!ansstack.empty())
        {
            ansstack.pop();
        }
    }
    
    void push(int x) {
        ansstack.push(x);
        if(minstack.empty())
        {
            minstack.push(x);
        }
        else if(x < minstack.top())
        {
            minstack.push(x);
        }
        else
        {
            minstack.push(minstack.top());
        }
    }
    
    void pop() {
        ansstack.pop();
        minstack.pop();
    }
    
    int top() {
        return ansstack.top();
    }
    
    int min() {
        return minstack.top();
    }
};
