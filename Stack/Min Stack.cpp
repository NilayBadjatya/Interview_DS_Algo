//We can also use another stacks instead of the map that will act as a min stack to store the minimum value.

class MinStack {
public:
    stack<int> st;
    map<int, int> mp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        mp[st.top()]--;
        if(mp[st.top()] == 0){
            mp.erase(st.top());
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mp.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
