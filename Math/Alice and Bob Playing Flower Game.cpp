class Solution {
public:
    long long flowerGame(int n, int m) {
        long long pairs = 0, even = 0, odd = 0;
        for(int i = 1; i <= m; i++){
            if(i % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }

        for(int i = 1; i <= n; i++){
            if(i % 2 == 0){
                pairs += odd;
            }else{
                pairs += even;
            }
        }

        return pairs;
    }
};
