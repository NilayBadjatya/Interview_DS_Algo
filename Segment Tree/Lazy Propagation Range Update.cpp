//T.C : O(logn)
//S.C : O(n)
//Assuming we have defined segmentTree[4*n] and lazyTree[4*n]
void updateRange(int start, int end, int val, int i, int l, int r, vector<int>& segTree, vector<int>& lazyTree){
    if(lazyTree[i] != 0){
        segTree[i] += (r - l + 1) * lazyTree[i];
        if(l != r){
            lazyTree[2*i+1] += lazyTree[i];
            lazyTree[2*i+2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }
    if(l > r || l > end || r < start){
        return;
    }
    if(l >= start && r <= end){
        segTree[i] += (r-l+1) * val;
        if(l != r){
            lazyTree[2*i+1] += val;
            lazyTree[2*i+2] += val;
        }
        return;
    }
    int mid = l + (r - l) / 2;
    updateRange(start, end, val, 2*i+1, l, mid, segTree, lazyTree);
    updateRange(start, end, val, 2*i+2, mid+1, r, segTree, lazyTree);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}
