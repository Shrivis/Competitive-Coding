class MyQueue {
    public:
    std::stack<int> s;
    std::stack<int> q;
    MyQueue() {
    }

    void push(int x) {
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!q.empty()) {
            s.push(q.top());
            q.pop();
        }
    }

    int pop() {
        auto a = s.top();
        s.pop();
        return a;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */