class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        // code here
        int n = arr.length;
        int startIdx = -1, endIdx = -1, maxLen = 0;
        int i = 0, j = 0;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        while(j < n){
            mp.put(arr[j], mp.getOrDefault(arr[j], 0) + 1);
            while(i < j && mp.lastKey() - mp.firstKey() > x){
                mp.put(arr[i], mp.get(arr[i]) - 1);
                if(mp.get(arr[i]) == 0){
                    mp.remove(arr[i]);
                }
                i++;
            }
            if(j - i + 1 > maxLen){
                maxLen = j - i + 1;
                startIdx = i;
                endIdx = j;
            }
            j++;
        }
        
        ArrayList<Integer> res = new ArrayList<>();
        for(int k = startIdx; k <= endIdx; k++){
            res.add(arr[k]);
        }
        return res;
    }
}
