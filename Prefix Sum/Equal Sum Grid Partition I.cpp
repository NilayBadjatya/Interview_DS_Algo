typedef long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<ll> h, v;

        //Collecting horizontal sums
        for(ll i = 0; i < m; i++){
            ll sum = 0;
            for(ll j = 0; j < n; j++){
                sum += grid[i][j];
            }
            h.push_back(sum);
        }

        //Collecting vertical sums
        for(ll j = 0; j < n; j++){
            ll sum = 0;
            for(ll i = 0; i < m; i++){
                sum += grid[i][j];
            }
            v.push_back(sum);
        }

        //Checking if a horizontal cut can be made
        ll hprefix = 0, sumh = accumulate(h.begin(), h.end(), 0LL);
        for(ll i = 0; i < m; i++){
            hprefix += h[i];
            if(hprefix == (sumh * 1.0 / 2)){
                return true;
            }
        }

        //Checking if a vertical cut can be made
        ll vprefix = 0, sumv = accumulate(v.begin(), v.end(), 0LL);
        for(ll i = 0; i < n; i++){
            vprefix += v[i];
            if(vprefix == (sumv * 1.0 / 2)){
                return true;
            }
        }

        return false; //No cut can be made
    }
};
