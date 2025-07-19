class Solution {
  public:
    int factorial(int n){
        int x = 1;
        for(int i = 1; i <= n; i++){
            x *= i;
        }
        return x;
    }
    int vowelCount(string& s) {
        // code here
        unordered_map<char, int> mp;
        for(auto& ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                mp[ch]++;
            }
        }
        int waysToSelect = 1;
        for(auto& x : mp){
            waysToSelect *= x.second;
        }
        int n = mp.size();
        if(n == 0) return 0;
        n = factorial(n);
        return waysToSelect * n;
    }
};
