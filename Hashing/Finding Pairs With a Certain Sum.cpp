class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i = 0; i < nums2.size(); i++){
            mp2[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        if(mp2[nums2[index]] == 0){
            mp2.erase(nums2[index]);
        }
        nums2[index] += val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for(int i = 0; i < nums1.size(); i++){
            int toFind = tot - nums1[i];
            if(mp2.count(toFind) != 0){
                count += mp2[toFind];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
