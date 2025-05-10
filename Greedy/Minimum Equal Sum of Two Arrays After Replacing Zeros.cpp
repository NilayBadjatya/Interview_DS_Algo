typedef long long ll;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n1 = nums1.size(), n2 = nums2.size();
        ll sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        ll sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        ll countZero1 = 0, countZero2 = 0;
        for(auto& x : nums1){
            if(x == 0){
                countZero1++;
            }
        }
        for(auto& x : nums2){
            if(x == 0){
                countZero2++;
            }
        }
        if(countZero1 == 0 && countZero2 == 0){
            if(sum1 != sum2){
                return -1;
            }
            return sum1;
        }
        else if(countZero1 == 0){
            sum2 += countZero2;
            if(sum1 < sum2){
                return -1;
            }
            return sum1;
        }else if(countZero2 == 0){
            sum1 += countZero1;
            if(sum1 > sum2){
                return -1;
            }
            return sum2;
        }
        return max(sum1 + countZero1, sum2 + countZero2);
    }
};
