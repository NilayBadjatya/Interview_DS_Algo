class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums2[i]] = i;
        }

        vector<int> nge(n, -1);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                nge[i] = -1;
            }else if(!st.empty() && st.top() <= nums2[i]){
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    nge[i] = -1;
                }else{
                    nge[i] = st.top();
                }
            }else{
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        int q = nums1.size();
        vector<int> ans;
        for(int i = 0; i < q; i++){
            int idx = mp[nums1[i]];
            ans.push_back(nge[idx]);
        }

        return ans;
    }
};
