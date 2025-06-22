class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < n; i++){
            temp += s[i];
            if(temp.size() == k){
                ans.push_back(temp);
                temp = "";
            }
        }
        if(temp.size() > 0){
        while(temp.size() < k){
            temp += fill;
        }
        ans.push_back(temp);
        }
        return ans;
    }
};
