class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> arr;
        for(int j = 0; j < n; j++){
            for(int k = j; k < n; k++){
                int x = nums[j] ^ nums[k];
                arr.insert(x);
            }
        }
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            for(auto& v : arr){
                int x = nums[i] ^ v;
                st.insert(x);
            }
        }
        return (int) st.size();
    }
};
