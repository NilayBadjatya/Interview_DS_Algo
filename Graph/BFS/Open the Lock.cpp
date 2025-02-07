class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        queue<string> q;
        q.push("0000");
        int mini = INT_MAX, level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string s = q.front();
                q.pop();
                if (s == target) {
                    return level;
                }
                if (st.count(s) != 0)
                    continue;
                st.insert(s);
                for (int i = 0; i < 4; i++) {
                    int x = s[i] - '0';
                    string t1 = s;
                    if (x + 1 > 9) {
                        t1[i] = '0';
                    }else{
                        t1[i] = (x+1) + '0';
                    }
                    if (st.count(t1) == 0) {
                        q.push(t1);
                    }
                    if (x - 1 < 0) {
                        t1[i] = '9';
                    }else{
                        t1[i] = (x-1) + '0';
                    }
                    if (st.count(t1) == 0) {
                        q.push(t1);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
