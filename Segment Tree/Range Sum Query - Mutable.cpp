class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildTree(int i, int l, int r, vector<int>& nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2*i+1, l, mid, nums);
        buildTree(2*i+2, mid+1, r, nums);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4 * n);
        buildTree(0, 0, n-1, nums);
    }
    
    void updateTree(int index, int val, int i, int l, int r){
        if(l == r){
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(index <= mid){
            updateTree(index, val, 2*i+1, l, mid);
        }else{
            updateTree(index, val, 2*i+2, mid+1, r);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);
    }
    
    int findQuery(int left, int right, int i, int l, int r){
        if(l >= left && r <= right){
            return segmentTree[i];
        }
        if(l > right || r < left){
            return 0;
        }
        int mid = l + (r - l) / 2;
        return findQuery(left, right, 2*i+1, l, mid) + findQuery(left, right, 2*i+2, mid+1, r);
    }

    int sumRange(int left, int right) {
        return findQuery(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
