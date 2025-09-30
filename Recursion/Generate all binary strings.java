class Solution {
    
    public void solve(ArrayList<String> arr, String s, int i, int n){
        if(i == n){
            arr.add(s);
            return;
        }
        solve(arr, s + "0", i+1, n);
        solve(arr, s + "1", i+1, n);
    }
    
    public ArrayList<String> binstr(int n) {
        // code here
        ArrayList<String> arr = new ArrayList<>();
        solve(arr,"", 0, n);
        return arr;
    }
}
