class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int i = 0, last = 0, maxi = 0;
        vector<int> ans;
        while(i < s.size()){
            if(mp[s[i]].back() == i && i >= maxi){
                ans.push_back(i+1 - last);
                last = i+1;
            }else{
                maxi = max(mp[s[i]].back(), maxi);
            }
            i++;
        }
        return ans;
    }
};
