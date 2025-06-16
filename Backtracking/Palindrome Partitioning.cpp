class Solution {
public:

    void solve(string s, int start, vector<string>& temp, vector<vector<string>>& list){
        if(start == s.size()){
            list.push_back(temp);
            return;
        }

        for(int i = start; i < s.size(); i++){
            string t = s.substr(0, i+1);
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(s.substr(i+1), 0, temp, list);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> list;
        solve(s, 0, temp, list);
        return list;
    }
};
