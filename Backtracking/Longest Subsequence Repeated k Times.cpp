class Solution {
public:
    string result = "";

    bool isSubsequence(string& s, string& curr, int k){
        int i = 0, j = 0;
        int m = curr.size();
        while(i < s.size() && j < (m * k)){
            if(s[i] == curr[j % m]){
                j++;
            }
            i++;
        }
        return j == (m * k);
    }

    void backTracking(string& s, string& curr, vector<bool>& canUse, vector<int>& reqFreq, int k, int maxLength){
        if(curr.size() > maxLength){
            return;
        }
        if(curr.size() <= maxLength && curr.size() >= result.size()){
            if(isSubsequence(s, curr, k)){
                result = max(result, curr);
            }
        }
        for(int i = 0; i < 26; i++){
            if(reqFreq[i] > 0){
                curr += (i + 'a');
                reqFreq[i]--;
                backTracking(s, curr, canUse, reqFreq, k, maxLength);
                curr.pop_back();
                reqFreq[i]++;
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(auto& ch : s){
            freq[ch - 'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> reqFreq(26, 0);
        for(int i = 0; i < 26; i++){
            if(freq[i] >= k){
                canUse[i] = true;
                reqFreq[i] = (freq[i] / k);
            }
        }

        int maxLength = n / k;
        string curr = "";
        backTracking(s, curr, canUse, reqFreq, k, maxLength);
        return result;
    }
};
