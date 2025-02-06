class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size(), maxDis = INT_MIN;
        unordered_map<char, char> dir;
        dir['W'] = 'E';
        dir['E'] = 'W';
        dir['N'] = 'S';
        dir['S'] = 'N';
        vector<string> d = {"NE", "NW", "SE", "SW"};
        for(int j = 0; j < 4; j++){
            int x = 0, y = 0, kk = k;
            string curr = d[j];
            for(int i = 0; i < n; i++){
                bool change = false;
                if(kk > 0 && s[i] != curr[0] && s[i] != curr[1]){
                    s[i] = dir[s[i]];
                    kk--;
                    change = true;
                }
                char now = s[i];
                if (now == 'N') {
                    y++;
                } else if (now == 'W') {
                    x--;
                } else if (now == 'S') {
                    y--;
                } else {
                    x++;
                }
                maxDis = max(maxDis, abs(x) + abs(y));
                if(change){
                    s[i] = dir[s[i]];
                }
            }
        }
        return maxDis;
    }
};
