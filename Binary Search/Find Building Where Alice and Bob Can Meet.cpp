//Time Complexity : O(Q * log(N) * log(N))
class Solution {
public:

    void buildTree(vector<int>& segTree, vector<int>& heights, int i, int l, int r){
        if(l == r){
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(segTree, heights, 2*i+1, l, mid);
        buildTree(segTree, heights, 2*i+2, mid+1, r);
        int leftIdx = segTree[2*i+1];
        int rightIdx = segTree[2*i+2];
        segTree[i] = (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    int querySegmentTree(int a, int b, int i, int l, int r, vector<int>& segTree, vector<int>& heights){
        if(l >= a && r <= b){
            return segTree[i];
        }
        if(l > b || r < a){
            return -1;
        }
        int mid = l + (r - l) / 2;
        int leftIdx = querySegmentTree(a, b, 2*i+1, l, mid, segTree, heights);
        int rightIdx = querySegmentTree(a, b, 2*i+2, mid+1, r, segTree, heights);
        if(leftIdx == -1){
            return rightIdx;
        }else if(rightIdx == -1){
            return leftIdx;
        }
        return (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    int RMIQ(vector<int>& segTree, vector<int>& heights, int n, int a, int b){
        return querySegmentTree(a, b, 0, 0, n-1, segTree, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& q) {
        int n = heights.size();
        vector<int> segTree(4 * n);
        buildTree(segTree, heights, 0, 0, n - 1);
        vector<int> result;
        for (auto& v : q) {
            int maxIdx = max(v[0], v[1]);
            int minIdx = min(v[0], v[1]);
            if(maxIdx == minIdx){
                result.push_back(maxIdx);
            }else if(heights[maxIdx] > heights[minIdx]){
                result.push_back(maxIdx);
            }else{
                int l = maxIdx+1;
                int r = n-1;
                int result_idx = -1;
                while(l <= r){
                    int mid = l + (r - l) / 2;
                    int idx = RMIQ(segTree, heights, n, l, mid);
                    if(heights[idx] > max(heights[maxIdx], heights[minIdx])){
                        result_idx = idx;
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
                result.push_back(result_idx);
            }
        }
        return result;
    }
};
