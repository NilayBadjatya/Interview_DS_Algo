//Approach 1: O(N^2)
class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i + k - 1 >= n) continue;
            int noOfWhites = 0;
            for(int j = i; j <= (i+k-1); j++){
                if(s[j] == 'W'){
                    noOfWhites++;
                }
            }
            ans = min(ans, noOfWhites);
        }
        return ans;
    }
};

//Approach 2(OPTIMAL): Sliding Window
//Time Complexity - O(N)
class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, noOfWhites = 0, ans = INT_MAX;
        while(j < n){
            if(s[j] == 'W'){
                noOfWhites++;
            }
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                ans = min(ans, noOfWhites);
                if(s[i] == 'W'){
                    noOfWhites--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
