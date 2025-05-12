class Solution {
public:

    void backTrack(vector<int>& digits, string s, unordered_set<int>& st, vector<bool> &isUsed){
        if(s.size() == 3){
            if(s[0] == '0') return;
            int x = stoi(s);
            if(x % 2 == 0){
                st.insert(x);
            }
            return;
        }
        for(int i = 0; i < digits.size(); i++){
            if(!isUsed[i]){
                isUsed[i] = true;
                s.push_back((digits[i] + '0'));
                backTrack(digits, s, st, isUsed);
                s.pop_back();
                isUsed[i] = false;
            }
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();
        vector<bool> isUsed(n+1, false);
        backTrack(digits, "", st, isUsed);
        vector<int> ans;
        for(auto& x : st){
            ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
