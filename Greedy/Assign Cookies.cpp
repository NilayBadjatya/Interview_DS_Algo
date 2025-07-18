class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();

        int i = 0, j = 0, content = 0;
        while(i < n && j < m){
            if(g[i] <= s[j]){
                content++;
                i++;
                j++;
            }else{
                j++;
            }
        }

        return content;
    }
};
