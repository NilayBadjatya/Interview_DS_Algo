class Solution {
    int n;

    public int solve(List<List<Integer>> triangle, int i, int j, int[][] dp){
        if(i == n){
            return 0;
        }
        if(dp[i][j] != 1e9){
            return dp[i][j];
        }
        int sum = triangle.get(i).get(j) + Math.min(solve(triangle, i+1, j, dp),
                                                     solve(triangle, i+1, j+1, dp));
        return dp[i][j] = sum;
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        n = triangle.size();
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] =(int) 1e9;
            }
        }
        return solve(triangle, 0, 0, dp);
    }
}
