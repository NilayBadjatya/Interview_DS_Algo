typedef long long ll;
class Solution {
public:
    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> nsl(n), nsr(n);
        for (int i = 0; i < n; i++) {
            if (!st.empty() && a[st.top()] <= a[i]) {
                nsl[i] = st.top();
            } else if (!st.empty() && a[st.top()] > a[i]) {
                while (!st.empty() && a[st.top()] > a[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    nsl[i] = -1;
                } else {
                    nsl[i] = st.top();
                }
            } else {
                nsl[i] = -1;
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n-1; i >= 0; i--) {
            if (!st.empty() && a[st.top()] < a[i]) {
                nsr[i] = st.top();
            } else if (!st.empty() && a[st.top()] >= a[i]) {
                while (!st.empty() && a[st.top()] >= a[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    nsr[i] = n;
                } else {
                    nsr[i] = st.top();
                }
            } else {
                nsr[i] = n;
            }
            st.push(i);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            ll freq = (i - nsl[i]) * (nsr[i] - i);
            ll t = a[i] * freq;
            sum = (sum + t) % MOD;
        }
        return sum;
    }
};
