const int M = 1e9+7;
const int N = 1e5+7;
const int Q = 80;
typedef long long ll;
class Solution {
public:
    int c[N][80];
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        c[0][0] = 1;
        c[1][0] = 1;
        c[1][1] = 1;
        for(int i = 1; i < n; i++){
            c[i][0] = 1; if(i < Q) c[i][i] = 1;
            for(int j = 1; j < k; j++){
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            int p = 0;
            for(int j = 0; j < k; j++){
                p = (p + c[n-i-1][j]) % M; 
            }
            p = ((ll)p * (ll)nums[i]) % M;
            sum = (sum + p) % M;
        }
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int p = 0;
            for(int j = 0; j < k; j++){
                p = (p + c[n-i-1][j]) % M; 
            }
            p = ((ll)p * (ll)nums[i]) % M;
            sum = (sum + p) % M;
        }
        return sum;
    }
};
