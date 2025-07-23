class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        stack<char> st;
        int points = 0;
        if(x > y){
            for(int i = 0; i < n; i++){
                if(!st.empty()){
                    if(s[i] == 'b' && st.top() == 'a'){
                        points += x;
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }
            s = "";
            while(!st.empty()){
                s += st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            for(int i = 0; i < s.size(); i++){
                if(!st.empty()){
                    if(s[i] == 'a' && st.top() == 'b'){
                        points += y;
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }
            return points;
        }else{
           for(int i = 0; i < n; i++){
                if(!st.empty()){
                    if(s[i] == 'a' && st.top() == 'b'){
                        points += y;
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }
            s = "";
            while(!st.empty()){
                s += st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            for(int i = 0; i < s.size(); i++){
                if(!st.empty()){
                    if(s[i] == 'b' && st.top() == 'a'){
                        points += x;
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }
            return points; 
        }
        return -1;
    }
};
