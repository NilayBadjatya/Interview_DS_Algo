class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(arr[i] <= k){
                sum --;
            }else{
                sum++;
            }
            if(sum > 0){
                ans = max(ans, i+1);
            }
            if(mp.count(sum-1) != 0){
                ans = max(ans, i - mp[sum-1]);
            }
            if(mp.count(sum) == 0){
                mp[sum] = i;
            }
        }
        return ans;
    }
};
