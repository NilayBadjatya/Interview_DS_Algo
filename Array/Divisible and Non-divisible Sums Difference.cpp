class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n * (n+1) / 2;
        int divSum = 0;
        for(int i = m; i <= n; i += m){
            divSum += i;
        }
        int nonDivSum = sum - divSum;
        return nonDivSum - divSum;
    }
};
