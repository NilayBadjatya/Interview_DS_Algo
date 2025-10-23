class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int i = 0, j = n-1, area = 0;
        while(i < j){
            int tempArea = Math.abs(i - j) * Math.min(height[i], height[j]);
            area = Math.max(area, tempArea);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
}
