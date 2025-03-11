//Time Complexity - O(N)
class Solution {
public:

    void buildTree(vector<int>& segTree, vector<int>& baskets, int i, int l, int r){
        if(l == r){
            segTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(segTree, baskets, 2*i+1, l, mid);
        buildTree(segTree, baskets, 2*i+2, mid+1, r);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }

    int findMaxi(vector<int>& segTree, int ele, int i, int l, int r){
        if(l == r){
            if(segTree[i] >= ele){
                segTree[i] = -1;
                return l;
            }
            return -1;
        }
        int mid = l + (r - l) / 2, x = -1;
        if(segTree[2*i+1] >= ele){
            x = findMaxi(segTree, ele, 2*i+1, l, mid);
        }else{
            x = findMaxi(segTree, ele, 2*i+2, mid+1, r);
        }
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return x;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = fruits.size();
        vector<int> segTree(4 * n);
        buildTree(segTree, baskets, 0, 0, n-1);
        int unplaced = 0;
        for(int i = 0; i < m; i++){
            int idx = findMaxi(segTree, fruits[i], 0, 0, n-1);
            if(idx == -1){
                unplaced++;
            }
        }
        return unplaced;
    }
};
