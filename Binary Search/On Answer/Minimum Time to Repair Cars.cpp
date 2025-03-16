typedef long long ll;
class Solution {
public:

    bool isValid(vector<int>& ranks, ll cars, ll mid){
        for(int i = 0; i < ranks.size(); i++){
            ll t = floor(mid * 1.0 / ranks[i]);
            ll root = sqrt(t);
            cars -= root;
        }
        return cars <= 0;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll maxi = *max_element(ranks.begin(), ranks.end());
        ll l = 1, r = maxi * (ll)cars * (ll)cars;
        ll ans = -1;
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(isValid(ranks, cars, mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
