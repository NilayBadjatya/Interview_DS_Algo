typedef long long ll;
class Solution {
public:

    ll check(vector<int>& nums1, vector<int>& nums2, ll midProduct){
        ll n = nums1.size();
        ll m = nums2.size();
        ll prevProdCount = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] >= 0){
                ll l = 0, r = m-1;
                ll curr = -1;
                while(l <= r){
                    ll mid = l + (r - l) / 2;
                    ll prod = 1LL * nums2[mid] * nums1[i];
                    if(prod > midProduct){
                        r = mid - 1;
                    }else{
                        curr = mid;
                        l = mid + 1;
                    }
                }
                prevProdCount += (curr + 1);
            }else{
                ll l = 0, r = m-1;
                ll curr = m;
                while(l <= r){
                    ll mid = l + (r - l) / 2;
                    ll prod = 1LL * nums2[mid] * nums1[i];
                    if(prod > midProduct){
                        l = mid + 1;
                    }else{
                        curr = mid;
                        r = mid - 1;
                    }
                }
                prevProdCount += (m - curr);
            }
        }
        return prevProdCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll result = 0;
        ll l = -1e10, r = 1e10;

        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(check(nums1, nums2, mid) >= k){
                result = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return result;
    }
};
