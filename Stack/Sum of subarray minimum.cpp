class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nsr(n, n), nsl(n, -1);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nsl[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nsr[i] = st.top();
            }
            st.push(i);
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            int freq = (nsr[i] - i) * (i - nsl[i]);
            sum += (freq * arr[i]);
        }
        return sum;
    }
};
