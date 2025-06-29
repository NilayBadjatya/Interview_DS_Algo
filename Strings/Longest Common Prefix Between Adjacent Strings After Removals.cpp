class Solution {
public:

    int computeLCP(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        int count = 0, i = 0;
        while(i < min(n, m)){
            if(s1[i] != s2[i]){
                break;
            }
            count++;
            i++;
        }
        return count;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> lcp(n, 0);
        for(int i = 1; i < n; i++){
            lcp[i] = computeLCP(words[i], words[i-1]);
        }

        vector<int> prefix(n), suffix(n);
        prefix[0] = 0;
        suffix[n-1] = 0;
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], lcp[i]);
        }
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], lcp[i+1]);
        }

        // for(auto& x : prefix){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(auto& x : suffix){
        //     cout << x << " ";
        // }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            int maxi = 0;
            if(i-1 >= 0){
                maxi = max(maxi, prefix[i-1]);
            }
            if(i+1 < n){
                maxi = max(maxi, suffix[i+1]);
            }
            if(i+1 < n && i-1 >= 0){
                maxi = max(maxi, computeLCP(words[i-1], words[i+1]));
            }
            ans[i] = maxi;
        }
        return ans;
    }
};
