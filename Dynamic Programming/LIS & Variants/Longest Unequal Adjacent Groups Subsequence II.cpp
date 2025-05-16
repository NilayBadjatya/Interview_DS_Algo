class Solution {
public:

    bool findHamming(vector<string>& words, int i, int prev){
        if(words[i].size() != words[prev].size()){
            return false;
        }
        int count = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(words[i][j] != words[prev][j]){
                count++;
            }
        }
        return count == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n+1, 1);
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int maxiIdx = 0, maxLen = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && findHamming(words, i, j)){
                    if(dp[j] + 1 > dp[i] && dp[j] + 1 >= maxLen){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dp[i] > maxLen){
                maxLen = dp[i];
                maxiIdx = i;
            }
        }
        cout << maxLen;
        vector<string> ans;
        int i = maxiIdx;
        while(parent[i] != i){
            ans.push_back(words[i]);
            i = parent[i];
        }
        ans.push_back(words[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
