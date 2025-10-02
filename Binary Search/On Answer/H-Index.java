class Solution {

    public static boolean isValid(int[] c, int hIndex){
        int count = 0;
        for(int cit : c){
            if(cit >= hIndex){
                count++;
            }
        }

        return count >= hIndex;
    }

    public int hIndex(int[] c) {
        int n = c.length;

        int low = 0, high = n, ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isValid(c, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
}
