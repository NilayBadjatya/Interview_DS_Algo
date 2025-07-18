typedef long long ll;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        ll size = nums.size();
        ll n = size / 3;

        priority_queue<ll> maxHeap;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        vector<ll> prefix(size, 0), suffix(size, 0);

        ll current_sum = 0;
        for(ll i = 0; i < size; i++){
            current_sum += nums[i];
            maxHeap.push(nums[i]);
            if(maxHeap.size() > n){
                current_sum -= maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == n){
                prefix[i] = current_sum;
            }
        }

        current_sum = 0;
        for(ll i = size-1; i >= 0; i--){
            current_sum += nums[i];
            minHeap.push(nums[i]);
            if(minHeap.size() > n){
                current_sum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n){
                suffix[i] = current_sum;
            }
        }

        // for(auto& x : prefix){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(auto& x : suffix){
        //     cout << x << " ";
        // }
        // cout << endl;

        ll min_diff = LLONG_MAX;
        for(ll i = n-1; i < 2*n; i++){
            min_diff = min(min_diff, prefix[i] - suffix[i+1]);
        }
        return min_diff;
    }
};
