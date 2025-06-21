class MyQueue {
public:
    stack<int> st;
    bool rev = false;
    MyQueue() {}

    void push(int x) {
        if(rev){
            stack<int> temp;
            int size = st.size();
            for (int i = 0; i < size; i++) {
                temp.push(st.top());
                st.pop();
            }
            rev = false;
            st = temp;
        }
        st.push(x);
        rev = false;
    }

    int pop() {
        if (!rev) {
            stack<int> temp;
            int size = st.size();
            for (int i = 0; i < size; i++) {
                temp.push(st.top());
                st.pop();
            }
            rev = true;
            st = temp;
        }
        int x = st.top();
        st.pop();
        return x;
    }

    int peek() {
        if (!rev) {
            stack<int> temp;
            int size = st.size();
            for (int i = 0; i < size; i++) {
                temp.push(st.top());
                st.pop();
            }
            st = temp;
            rev = true;
        }
        return st.top();
    }

    bool empty() { return st.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
