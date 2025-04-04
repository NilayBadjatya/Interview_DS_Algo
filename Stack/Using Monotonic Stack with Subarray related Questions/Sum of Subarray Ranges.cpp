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
        //Next Larger To Left
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

//Optimal JAVA Solution
class Solution {
    public long subArrayRanges(int[] nums) {
        int n = nums.length;
        int[] nsl = new int[n], nsr = new int[n], nll = new int[n], nlr = new int[n];
        Stack<Integer> st = new Stack<>();
        //Next Smalonger To Left
        for(int i = 0; i < n; i++){
            if(!st.empty() && nums[st.peek()] <= nums[i]){
                nsl[i] = st.peek();
            }else if(!st.empty() && nums[st.peek()] > nums[i]){
                while(!st.empty() && nums[st.peek()] > nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }else{
                    nsl[i] = st.peek();
                }
            }else{
                nsl[i] = -1;
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        //Next Smalonger To Right
        for(int i = n-1; i >= 0; i--){
            if(!st.empty() && nums[st.peek()] < nums[i]){
                nsr[i] = st.peek();
            }else if(!st.empty() && nums[st.peek()] >= nums[i]){
                while(!st.empty() && nums[st.peek()] >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }else{
                    nsr[i] = st.peek();
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
            if(!st.empty() && nums[st.peek()] >= nums[i]){
                nll[i] = st.peek();
            }else if(!st.empty() && nums[st.peek()] < nums[i]){
                while(!st.empty() && nums[st.peek()] < nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nll[i] = -1;
                }else{
                    nll[i] = st.peek();
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
            if(!st.empty() && nums[st.peek()] > nums[i]){
                nlr[i] = st.peek();
            }else if(!st.empty() && nums[st.peek()] <= nums[i]){
                while(!st.empty() && nums[st.peek()] <= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nlr[i] = n;
                }else{
                    nlr[i] = st.peek();
                }
            }else{
                nlr[i] = n;
            }
            st.push(i);
        }
        long maxi = 0, mini = 0;
        for(int i = 0; i < n; i++){
            long leftS = i - nsl[i];
            long rightS = nsr[i] - i;
            long total = leftS * rightS;
            mini += (total * (long)nums[i]);
            leftS = i - nll[i];
            rightS = nlr[i] - i;
            total = leftS * rightS;
            maxi += (total * (long)nums[i]);
        }
        return maxi - mini;
    }
}
