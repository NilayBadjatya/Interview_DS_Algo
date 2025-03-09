//Time Complexity - O(NLogN)
typedef long long ll;
typedef pair<int, int> P;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<ll> ans(n, 0);
        vector<P> a(n);
        for (int i = 0; i < n; i++) {
            a[i].first = nums1[i];
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        ll currSum = 0;
        for (int i = 0; i < n; i++) {
            int ele = a[i].first;
            int idx = a[i].second;
            if(i > 0 && a[i].first == a[i-1].first){
                ans[idx] = ans[a[i-1].second];
            }
            if (pq.size() == 0 || (i > 0 && a[i].first <= a[i - 1].first)) {
                if (pq.size() < k) {
                    pq.push(nums2[idx]);
                    currSum += nums2[idx];
                } else if (nums2[idx] > pq.top()) {
                    currSum -= pq.top();
                    pq.pop();
                    pq.push(nums2[idx]);
                    currSum += nums2[idx];
                }
                continue;
            }
            ans[idx] = currSum;
            if (pq.size() < k) {
                pq.push(nums2[idx]);
                currSum += nums2[idx];
            } else if (nums2[idx] > pq.top()) {
                currSum -= pq.top();
                pq.pop();
                pq.push(nums2[idx]);
                currSum += nums2[idx];
            }
        }
        return ans;
    }
};
