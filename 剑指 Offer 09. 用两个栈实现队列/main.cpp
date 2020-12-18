class CQueue {
private:

stack<int> left;
stack<int> right;

public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        left.push(value);
    }
    
    int deleteHead() {
        if(left.empty() && right.empty())
            return -1;
        if(!right.empty())
        {
            int tem = right.top();
            right.pop();
            return tem;
        }
        else
        {
            while(!left.empty())
            {
                int tem = left.top();
                right.push(tem);
                left.pop();
            }
            int tem = right.top();
            right.pop();
            return tem;
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */