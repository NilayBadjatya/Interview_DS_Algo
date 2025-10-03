class Solution {
    
    public static void solve(int[] arr, int start, StringBuilder temp, ArrayList<String> list, HashMap<Integer, char[]> mp){
        if(start == arr.length){
            list.add(temp.toString());
            return;
        }
        if(arr[start] == 0 || arr[start] == 1){
            solve(arr, start+1, temp, list, mp);
        }
        for(char c : mp.get(arr[start])){
            temp.append(c);
            solve(arr, start+1, temp, list, mp);
            temp.deleteCharAt(temp.length() - 1);
        }
    }
    
    public ArrayList<String> possibleWords(int[] arr) {
        // code here
        ArrayList<String> list = new ArrayList<>();
        HashMap<Integer, char[]> mp = new HashMap<>();
        mp.put(0, new char[]{});
        mp.put(1, new char[]{});
        mp.put(2, new char[]{'a', 'b', 'c'});
        mp.put(3, new char[]{'d', 'e', 'f'});
        mp.put(4, new char[]{'g', 'h', 'i'});
        mp.put(5, new char[]{'j', 'k', 'l'});
        mp.put(6, new char[]{'m', 'n', 'o'});
        mp.put(7, new char[]{'p', 'q', 'r', 's'});
        mp.put(8, new char[]{'t', 'u', 'v'});
        mp.put(9, new char[]{'w', 'x', 'y', 'z'});
        solve(arr, 0, new StringBuilder(), list, mp);
        return list;
    }
}
