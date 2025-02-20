class Solution {
public:

    string solve(string s, int n, unordered_set<string>& st){
        if(s.size() == n){
            if(st.count(s) == 0){
                return s;
            }
            return "";
        }
        if(s.size() > n){
            return "";
        }
        for(auto i = '0'; i <= '1'; i++){
            s += i;
            string res = solve(s, n, st);
            if(!res.empty()) return res;
            s.pop_back();
        }
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        return solve("", n, st);
    }
};
