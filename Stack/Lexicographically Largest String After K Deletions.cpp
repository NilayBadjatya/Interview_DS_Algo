typedef pair<char, int> P;
class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() < s[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        
        while(k--){
            st.pop();
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
