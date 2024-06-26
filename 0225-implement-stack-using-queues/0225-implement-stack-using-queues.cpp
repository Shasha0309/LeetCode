class MyStack {
public:
queue<int> que1;
    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
        int n = que1.size();
        for(int i=0;i<n-1;i++){
            que1.push(que1.front());
            que1.pop();
        }
    }
    
    int pop() {
        int result = que1.front();
        que1.pop();
        return result;
    }
    
    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.empty();
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