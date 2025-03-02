// Approach 1: Using HashMap
// Time Complexity - O(N+N+N) ~ O(N)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        map<int, int> mp;
        for(auto &v : nums1){
            int id = v[0];
            int val = v[1];
            mp[id] += v[1];
        }
        for(auto &v : nums2){
            int id = v[0];
            int val = v[1];
            mp[id] += v[1];
        }
        vector<vector<int>> res;
        for(auto &x : mp){
            int id = x.first;
            int val = x.second;
            res.push_back({id, val});
        }
        return res;
    }
};

//Approach 2: Two Pointer Optimal
//Time Complexity - O(N)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j =0;
        vector<vector<int>> res;
        while(i < n && j < m){
            if(nums1[i][0] < nums2[j][0]){
                res.push_back(nums1[i]);
                i++;
            }else if(nums1[i][0] > nums2[j][0]){
                res.push_back(nums2[j]);
                j++;
            }else{
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }
        while(i < n){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
};
