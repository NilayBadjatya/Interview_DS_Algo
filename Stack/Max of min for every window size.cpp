class Solution {
  public:
  
    vector<int> NSL(vector<int>& arr){
        int n = arr.size();
        vector<int> nsl(n, -1);
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
        return nsl;
    }
    
    vector<int> NSR(vector<int>& arr){
        int n = arr.size();
        vector<int> nsr(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }
  
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> prevSmaller = NSL(arr);
        vector<int> nextSmaller = NSR(arr);
        
        vector<int> ans(n+1, 0);
        for(int i = 0; i < n; i++){
            int len = nextSmaller[i] - prevSmaller[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        
        for(int i = n-1; i >= 1; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};
