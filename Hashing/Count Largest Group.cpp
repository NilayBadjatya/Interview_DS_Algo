class Solution {
public:

    int findSum(int x){
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        int maxi = INT_MIN;
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++){
            int sum = findSum(i);
            mp[sum]++;
            maxi = max(maxi, mp[sum]);
        }
        int groups = 0;
        for(auto& x : mp){
            if(x.second == maxi){
                groups++;
            }
        }
        return groups;
    }
};
