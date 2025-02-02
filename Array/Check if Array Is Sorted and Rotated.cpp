//Brute Force O(n^2)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        sort(a.begin(), a.end());
        for (int j = 0; j < n; j++) {
            bool flag = true;
            int k = j;
            for (int i = 0; i < n; i++) {
                if (a[i] != nums[k]) {
                    flag = false;
                    break;
                }
                k = (k+1) % n;
            }
            if(flag) return true;
        }
        return false;
    }
};

//Optimal Approach O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1) % n]){
                peak++;
            }
            if(peak > 1){
                return false;
            }
        }
        return true;
    }
};
