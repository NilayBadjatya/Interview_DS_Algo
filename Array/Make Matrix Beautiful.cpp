class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int maxSum = 0;
        for(int i = 0; i < n; i++){
            int temp = 0, temp2 = 0;
            for(int j = 0; j < n; j++){
                temp += mat[i][j];
                temp2 += mat[j][i];
            }
            maxSum = max(maxSum, max(temp, temp2));
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = 0; j < n; j++){
                temp += mat[i][j];
            }
            ans += maxSum - temp;
        }
        return ans;
    }
};
