class Solution {
    public int romanToInt(String s) {
        int n = s.length();
        HashMap<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        int num = 0;
        for(int i = 0; i < n; i++){
            if(i < n-1 && mp.get(s.charAt(i)) < mp.get(s.charAt(i+1))){
                num += mp.get(s.charAt(i + 1)) - mp.get(s.charAt(i));
                i++;
            }else{
                num += mp.get(s.charAt(i));
            }
        }
        return num;
    }
}

------------------------------------ C++ ---------------------------------

  class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int n = s.size(), num = 0;
        for(int i = 0; i < n; i++){
            if(i < n-1 && mp[s[i]] < mp[s[i+1]]){
                num += (mp[s[i + 1]] - mp[s[i]]);
                i++;
            }else{
                num += mp[s[i]];
            }
        }
        return num;
    }
};
