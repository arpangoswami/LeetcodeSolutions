class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return val;
    }
    
    int top() {
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        q.push(val);
        return val;
    }
    
    bool empty() {
        return q.empty();
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