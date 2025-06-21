class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();

        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            freq[word[i] - 'a']++;
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i < 26; i++){
            if(freq[i] == 0) continue;
            int tempAns = 0;
            for(int j = 0; j < 26; j++){
                if(freq[j] == 0 || j == i) continue;
                if(freq[j] < freq[i]){
                    tempAns += freq[j];
                    continue;
                }
                int a = freq[i];
                int b = freq[j];
                int diff = abs(b - a);
                if(diff > k){
                    tempAns += (diff - k);
                }
            }
            ans = min(ans, tempAns);
        }

        return ans;
    }
};
