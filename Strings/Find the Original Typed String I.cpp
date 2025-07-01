class Solution {
public:
    int possibleStringCount(string s) {
        int n = s.size();
        int i = 1, curr = 0, ans = 0, count = -1;
        while(i < n){
            while(i < n && s[i] == s[i-1]){
                curr++;
                i++;
            }
            if(curr > 0){
                ans += (curr + 1);
                curr = 0;
                count++;
            }
            i++;
        }
        if(ans == 0){
            return 1;
        }
        return ans - count;
    }
};
