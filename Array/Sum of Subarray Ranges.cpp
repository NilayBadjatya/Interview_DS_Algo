//Brute Force JAVA
class Solution {
    public long subArrayRanges(int[] nums) {
        int n = nums.length;
        long sum = 0;
        for(int i = 0; i < n; i++){
            int maxi = Integer.MIN_VALUE, mini = Integer.MAX_VALUE;
            for(int j = i; j < n; j++){
                maxi = Math.max(maxi, nums[j]);
                mini = Math.min(mini, nums[j]);
                sum += (maxi - mini);
            }
        }
        return sum;
    }
}

//Optimal C++

typedef long long ll;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nsl(n), nsr(n), nll(n), nlr(n);
        stack<int> st;
        //Next Smaller To Left
        for(int i = 0; i < n; i++){
            if(!st.empty() && nums[st.top()] <= nums[i]){
                nsl[i] = st.top();
            }else if(!st.empty() && nums[st.top()] > nums[i]){
                while(!st.empty() && nums[st.top()] > nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }else{
                    nsl[i] = st.top();
                }
            }else{
                nsl[i] = -1;
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        //Next Smaller To Right
        for(int i = n-1; i >= 0; i--){
            if(!st.empty() && nums[st.top()] < nums[i]){
                nsr[i] = st.top();
            }else if(!st.empty() && nums[st.top()] >= nums[i]){
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }else{
                    nsr[i] = st.top();
                }
            }else{
                nsr[i] = n;
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        //Next Larger To Left
        for(int i = 0; i < n; i++){
            if(!st.empty() && nums[st.top()] >= nums[i]){
                nll[i] = st.top();
            }else if(!st.empty() && nums[st.top()] < nums[i]){
                while(!st.empty() && nums[st.top()] < nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nll[i] = -1;
                }else{
                    nll[i] = st.top();
                }
            }else{
                nll[i] = -1;
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        //Next Larger To Right
        for(int i = n-1; i >= 0; i--){
            if(!st.empty() && nums[st.top()] > nums[i]){
                nlr[i] = st.top();
            }else if(!st.empty() && nums[st.top()] <= nums[i]){
                while(!st.empty() && nums[st.top()] <= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nlr[i] = n;
                }else{
                    nlr[i] = st.top();
                }
            }else{
                nlr[i] = n;
            }
            st.push(i);
        }
        ll maxi = 0, mini = 0;
        for(int i = 0; i < n; i++){
            ll leftS = i - nsl[i];
            ll rightS = nsr[i] - i;
            ll total = leftS * rightS;
            mini += (total * (ll)nums[i]);
            leftS = i - nll[i];
            rightS = nlr[i] - i;
            total = leftS * rightS;
            maxi += (total * (ll)nums[i]);
        }
        return maxi - mini;
    }
};
