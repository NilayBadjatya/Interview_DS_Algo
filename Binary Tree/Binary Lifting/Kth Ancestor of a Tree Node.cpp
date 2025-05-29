class TreeAncestor {
public:
    vector<int> parent;
    vector<vector<int>> dp;
    int n;
    TreeAncestor(int n, vector<int>& parent) {
        this->parent = parent;
        this->n = n;
        dp.resize(17, vector<int> (n, -1));
        for(int i = 0; i < n; i++){
            dp[0][i] = parent[i];
        }
        for(int i = 1; i < 17; i++){
            for(int j = 0; j < n; j++){
                if(dp[i-1][j] >= 0){
                    dp[i][j] = dp[i-1][dp[i-1][j]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 17; i++){
            int bit = (k >> i) & 1;
            if(bit){
                node = dp[i][node];
                if(node == -1){
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
