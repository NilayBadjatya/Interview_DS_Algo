class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto& x : arr){
            mp[x]++;
        }
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = mp[arr[i]];
        }
        
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && mp[st.top()] <= mp[arr[i]]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
