class Solution {
  public:
  
    vector<int> NGR(vector<int>& nums){
        stack<int> st;
        vector<int> arr = nums;
        for(int i = 0; i < nums.size(); i++){
            arr.push_back(nums[i]);
        }
        int n = arr.size();
        vector<int> ngr(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.size() == 0){
                ngr[i] = -1;
            }else{
                ngr[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ngr;
    }
  
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> ngr = NGR(arr);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(ngr[i] != -1){
                ans[i] = ngr[i];
            }else{
                ans[i] = -1;
            }
        }
        return ans;
    }
};
