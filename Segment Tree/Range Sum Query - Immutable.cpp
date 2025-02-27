class NumArray {
public:
    int n;
    vector<int> segmentTree;
    void buildTree(int i, int l, int r, vector<int>& nums, vector<int>& segmentTree){
        if(l == r){
            segmentTree[i] = nums[r];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2*i+1, l, mid, nums, segmentTree);
        buildTree(2*i+2, mid+1, r, nums, segmentTree);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildTree(0,0,n-1, nums, segmentTree); 
    }

    int findQuery(int left, int right, int i, int l, int r){
        if(l >= left && r <= right){
            return segmentTree[i];
        }
        if(l > right || r < left){
            return 0;
        }
        int mid = l + (r - l) / 2;
        return findQuery(left, right, 2*i+1, l, mid) + findQuery(left, right, 2*i+2, mid + 1, r);
    }
    
    int sumRange(int left, int right) {
        return findQuery(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
