class RandomizedSet {
    HashMap<Integer, Integer> mp;
    ArrayList<Integer> arr;
    public RandomizedSet() {
        mp = new HashMap<Integer, Integer>();
        arr = new ArrayList<Integer>();
    }
    
    public boolean insert(int val) {
        if(mp.containsKey(val)){
            return false;
        }
        arr.add(val);
        mp.put(val, arr.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if(!mp.containsKey(val)){
            return false;
        }
        int idx = mp.get(val);
        int lastVal = arr.get(arr.size()-1);

        arr.set(idx, lastVal);
        mp.put(lastVal, idx);

        arr.remove(arr.size() - 1);
        mp.remove(val);
        return true;
    }
    
    public int getRandom() {
        int idx = (int)(Math.random() * arr.size());
        return arr.get(idx);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
