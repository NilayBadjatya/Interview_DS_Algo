class Solution {
    
    public static void solve(int[] arr, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> list, boolean[] isUsed){
        if(temp.size() == arr.length){
            list.add(new ArrayList<>(temp));
            return;
        }
        
        for(int i = 0; i < arr.length; i++){
            if(i > 0 && arr[i] == arr[i-1] && isUsed[i-1] == true || isUsed[i] == true) continue;
            temp.add(arr[i]);
            isUsed[i] = true;
            solve(arr, temp, list, isUsed);
            temp.remove(temp.size() - 1);
            isUsed[i] = false;
        }
    }
    
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] arr) {
        // code here
        int n = arr.length;
        Arrays.sort(arr);
        ArrayList<Integer> temp = new ArrayList<>();
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        boolean[] isUsed = new boolean[n];
        for(int i = 0; i < n; i++){
            isUsed[i] = false;
        }
        solve(arr, temp, list, isUsed);
        return list;
    }
};
