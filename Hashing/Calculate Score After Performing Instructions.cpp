typedef long long ll;
class Solution {
public:
    long long calculateScore(vector<string>& nums, vector<int>& val) {
        int n = nums.size(), i = 0;
        ll ans = 0;
        unordered_set<int> st;
        while(i >= 0 && i < n){
            if(nums[i][0] == 'j'){
                if(st.count(i) != 0){
                    break;
                }
                st.insert(i);
                i = i + val[i];
            }else{
                if(st.count(i) != 0){
                    break;
                }
                ans += val[i];
                st.insert(i);
                i++;
            }
        }
        return ans;
    }
};
