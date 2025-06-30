typedef long long ll;
typedef pair<ll, ll> P;
class Solution {
  public:
  
    bool isValid(vector<int> &nums, ll mid, ll k, ll w){
        int n = nums.size();
        vector<ll> add(n+1, 0);
        int currWater = 0;
        for(int i = 0; i < n; i++){
            currWater += add[i];
            ll effectiveHeight = nums[i] + currWater;
            if(effectiveHeight < mid){
                ll need = mid - effectiveHeight;
                k -= need;
                if(k < 0){
                    return false;
                }
                currWater += need;
                if(i+w < n){
                    add[i+w] -= need;
                }
            }
        }
        return true;
    }
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        ll l = *min_element(arr.begin(), arr.end());
        ll r = *max_element(arr.begin(), arr.end()) + k;
        ll ans = l;
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(isValid(arr, mid, k, w)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
