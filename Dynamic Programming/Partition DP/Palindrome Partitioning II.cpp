class Solution {
public:

    int solve(string& s, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& pali){
        if(i >= j){
            return 0;
        }

        if(pali[i][j]){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int cost = 1e9;
        for(int k = i; k <= j; k++){
            // string t = s.substr(i, k-i+1);
            if(pali[i][k]){
                cost = min(cost, 1 + solve(s, k+1, j, dp, pali));
            }
        }
        return dp[i][j] = cost;
    }

    bool isPalindrome(string& s, int st, int e){
        int i = st, j = e;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pali(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    pali[i][j] = true;
                }
            }
        }
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(s, 0, n-1, dp, pali);
    }
};
