typedef long long ll;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1){
            return 'a';
        }
        int n = operations.size();
        ll newK = 1;
        ll len = 1;
        ll newOps = -1;
        for(int i = 0; i < n; i++){
            len *= 2;
            if(len >= k){
                newK = k - len / 2;
                newOps = operations[i];
                break;
            }
        }
        char ch = kthCharacter(newK, operations);
        if(newOps == 1){
            return ch == 'z' ? 'a' : ch + 1;
        }
        return ch;
    }
};
