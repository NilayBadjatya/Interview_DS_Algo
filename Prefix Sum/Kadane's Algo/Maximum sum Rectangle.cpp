class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int maxsum = INT_MIN;
        for(int i = 0; i < m; i++){
            vector<int> arr(n, 0);
            for(int j = i; j < m; j++){
                for(int k = 0; k < n; k++){
                    arr[k] += mat[k][j];
                }
                int sum = 0;
                for(int l = 0; l < n; l++){
                    sum += arr[l];
                    maxsum = max(maxsum, sum);
                    if(sum < 0){
                        sum = 0;
                    }
                }
            }
        }
        return maxsum;
    }
};
