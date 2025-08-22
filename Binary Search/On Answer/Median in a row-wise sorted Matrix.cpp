class Solution {
  public:
  
    int isValid(vector<vector<int>> &mat, int mid){
        int n = mat.size();
        int m = mat[0].size();
        int ele = 0;
        for(int i = 0; i < n; i++){
            int idx = lower_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            ele += idx;
        }
        return ele;
    }
  
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int expected = (n * m) / 2;
        int l = 1, r = 2000, ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int ele = isValid(mat, mid);
            // if(ele == expected) return mid;
            if(ele > expected){
                r = mid - 1;
            }else{
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};
