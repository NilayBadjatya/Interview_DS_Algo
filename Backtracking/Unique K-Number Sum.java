class Solution {
    
    public static void solve(ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> list, int n, int k, int start){
        if(n == 0 && k == 0){
            list.add(new ArrayList<>(temp));
            return;
        }
        if(n < 0 || k == 0){
            return;
        }
        
        for(int i = start; i <= 9; i++){
            temp.add(i);
            solve(temp, list, n - i, k-1, i+1);
            temp.remove(temp.size() - 1);
        }
    }
    
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        // code here
        ArrayList<Integer> temp = new ArrayList<>();
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        solve(temp, list, n, k, 1);
        return list;
    }
}
