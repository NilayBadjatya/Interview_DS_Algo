//Approach 1: O(N^2)
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            char orig = secret[i];
            if(orig == guess[i]){
                bulls++;
                continue;
            }   
            for(int j = 0 ; j < n; j++){
                if(orig == guess[j] && secret[j] != guess[j] && !visited[j]){
                    cows++;
                    visited[j] = true;
                    break;
                }
            }
        }
        string s = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return s;
    }
};
