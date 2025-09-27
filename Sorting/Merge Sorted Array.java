class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(m == 0){
            int jj = 0;
            for(int ii = 0; ii < m+n; ii++){
                nums1[ii] = nums2[jj++];
            }
            return;
        }
        if(n == 0){
            return;
        }
        int i = m-1, k = m + n - 1, j = n-1;
        while(j >= 0 && i >= 0){
            if(nums1[i] <= nums2[j]){
                nums1[k] = nums2[j];
                j--;
            }else{
                nums1[k] = nums1[i];
                nums1[i] = nums2[j];
                i--;
            }
            k--;
        }  
        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
}
