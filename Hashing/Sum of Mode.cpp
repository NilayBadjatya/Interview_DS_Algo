class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0, sum = 0;
        unordered_map<int, int> mp;
        map<int, set<int>> freq;
        while(j < n){
            int oldF = mp[arr[j]];
            if (oldF > 0) {
                freq[oldF].erase(arr[j]);
                if (freq[oldF].empty()) freq.erase(oldF);
            }
            mp[arr[j]]++;
            freq[mp[arr[j]]].insert(arr[j]);
            if(j - i + 1 == k){
                sum += *freq.rbegin()->second.begin();
                int f = mp[arr[i]];
                freq[f].erase(arr[i]);
                if(freq[f].empty()){
                    freq.erase(f);
                }
                mp[arr[i]]--;
                if(mp[arr[i]] > 0){
                    freq[mp[arr[i]]].insert(arr[i]);
                }
                i++;
            }
            j++;
        }
        return sum;
    }
};
