typedef long long ll;
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<ll> prefix(n, 0), suffix(n, 0);
        if(s[0] == 'L'){
            prefix[0] = 1;
        }
        if(s[n-1] == 'T'){
            suffix[n-1] = 1;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == 'L'){
                prefix[i] = prefix[i-1] + 1;
            }else{
                prefix[i] = prefix[i-1];
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(s[i] == 'T'){
                suffix[i] = suffix[i+1] + 1;
            }else{
                suffix[i] = suffix[i+1];
            }
        }

        ll initial = 0;
        for(int i = 1; i < n-1; i++){
            if(s[i] == 'C'){
                initial += (prefix[i-1] * suffix[i+1]);
            }
        }

        ll extra = 0;

        // Inserting 'L'
        ll tempExtra = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == 'C'){
                tempExtra += (1 * suffix[i+1]);
            }
        }
        extra = max(extra, tempExtra);

        // Inserting 'T'
        tempExtra = 0;
        for(int i = n-1; i > 0; i--){
            if(s[i] == 'C'){
                tempExtra += (1 * prefix[i-1]);
            }
        }
        extra = max(extra, tempExtra);

        // Inserting 'C'
        tempExtra = 0;
        for(int i = 0; i < n; i++){
            tempExtra = (prefix[i] * suffix[i]);
            extra = max(extra, tempExtra);
        }

        return initial + extra;
    }
};
