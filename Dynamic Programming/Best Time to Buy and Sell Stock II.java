class Solution {

    public int solve(int[] prices, int i, int buy, int[][] dp){
        if(i == prices.length){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = Integer.MIN_VALUE;
        if(buy == 0){
            profit = -prices[i] + solve(prices, i+1, 1, dp);
        }else{
            profit = prices[i] + solve(prices, i+1, 0, dp); 
        }
        profit = Math.max(profit, solve(prices, i+1, buy, dp));
        return dp[i][buy] = profit;
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(prices, 0, 0, dp);
    }
}
