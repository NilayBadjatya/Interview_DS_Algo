class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                if(st.empty() == true) continue;
                s[st.top()] = '*';
                s[i] = '*';
                st.pop();
            }else{
                st.push(i);
            }
        }
        string res = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '*'){
                res += s[i];
            }
        }
        return res;
    }
};
