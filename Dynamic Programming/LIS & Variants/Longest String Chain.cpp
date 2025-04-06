//C++ Code
class Solution {
public:

    bool isValid(string& prev, string& s){
        int n = prev.size();
        int m = s.size();
        if(abs(n-m) != 1){
            return false;
        }
        int i = 0, j = 0;
        while(i < n && j < m){
            if(prev[i] == s[j]){
                i++;
            }
            j++;
        }
        return i == n;
    }
    int dp[1001][1001];
    int solve(vector<string>& words, int i, int prev){
        if(i == words.size()){
            return 0;
        }
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }
        int take = 0, skip = 0;
        if(prev == -1 || isValid(words[prev], words[i])){
            take = 1 + solve(words, i+1, i);
        }
        skip = solve(words, i+1, prev);
        if(prev != -1){
            return dp[i][prev] = max(take, skip);
        }
        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string& a, string& b){
            if(a.size() == b.size()){
                return a < b;
            }
            return a.size() < b.size();
        });
        memset(dp, -1, sizeof(dp));
        return solve(words, 0, -1);
    }
};

//Java Code
class Solution {

    private boolean isValid(String prev, String s){
        int n = prev.length();
        int m = s.length();
        if(Math.abs(n-m) != 1){
            return false;
        }
        int i = 0, j = 0;
        while(i < n && j < m){
            if(prev.charAt(i) == s.charAt(j)){
                i++;
            }
            j++;
        }
        return i == n;
    }
    int[][] dp;
    private int solve(String[] words, int i, int prev){
        if(i == words.length){
            return 0;
        }
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }
        int take = 0, skip = 0;
        if(prev == -1 || isValid(words[prev], words[i])){
            take = 1 + solve(words, i+1, i);
        }
        skip = solve(words, i+1, prev);
        if(prev != -1){
            return dp[i][prev] = Math.max(take, skip);
        }
        return Math.max(take, skip);
    }

    public int longestStrChain(String[] words) {
        int n = words.length;
        Arrays.sort(words, (a, b) ->
            a.length() - b.length()
        );
        dp = new int[n][n];
        for(int[] row:dp){
            Arrays.fill(row, -1);
        }
        return solve(words, 0, -1);
    }
}
