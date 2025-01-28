class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> t = nums;
        sort(t.begin(), t.end());
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> mp2;
        int grpNo = 0;
        mp[grpNo].push_back(t[n-1]);
        for(int i = n-2; i >= 0; i--){
            if((t[i+1]-t[i]) <= limit){
                mp[grpNo].push_back(t[i]);
                mp2[t[i]] = grpNo;
            }else{
                grpNo++;
                mp[grpNo].push_back(t[i]);
                mp2[t[i]] = grpNo;
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            int grpno = mp2[nums[i]];
            if(mp[grpno].size() > 0)
            {res.push_back(mp[grpno].back());
            mp[grpno].pop_back();}
        }
        return res;
    }
};
