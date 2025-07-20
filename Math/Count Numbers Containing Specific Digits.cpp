class Solution {
  public:
  
    int findPower(int a, int b){
        if(b == 0){
            return 1;
        }
        long long half = findPower(a, b/2);
        long long result = half * half;
        if(b % 2 != 0){
            result = result * a;
        }
        return result;
    }
  
    int countValid(int n, vector<int>& arr) {
        // code here
        int total = 9 * findPower(10, n-1);
        unordered_set<int> st(arr.begin(), arr.end());
        int c = 0;
        bool zeroPresentInArr = false;
        if(st.count(0) != 0){
            zeroPresentInArr = true;
        }
        for(int i = 0; i <= 9; i++){
            if(st.count(i) == 0){
                c++;
            }
        }
        int avoid = 0;
        if(zeroPresentInArr){
            avoid = findPower(c, n);
        }else{
            avoid = (c-1) * findPower(c, n-1);
        }
        return total - avoid;
    }
};
