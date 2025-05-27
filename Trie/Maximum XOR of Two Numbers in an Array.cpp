class Solution {
public:

    struct trieNode{
        trieNode* left = NULL;
        trieNode* right = NULL;
    };

    void insert(int x, trieNode* root){
        trieNode* crawler = root;
        for(int i = 31; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(bit == 0){
                if(crawler->left == NULL){
                    crawler->left = new trieNode();
                }
                crawler = crawler->left;
            }else{
                if(crawler->right == NULL){
                    crawler->right = new trieNode();
                }
                crawler = crawler->right;
            }
        }
    }

    int findMaxXor(int num, trieNode* root){
        trieNode* crawler = root;
        int ele = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(bit == 0){
                if(crawler->right == NULL){
                    crawler = crawler->left;
                }else{
                    crawler = crawler->right;
                    ele |= (1 << i);
                }
            }else{
                if(crawler->left == NULL){
                    crawler = crawler->right;
                }else{
                    ele |= (1 << i);
                    crawler = crawler->left;
                }
            }
        }
        return ele;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        trieNode* root = new trieNode();
        for(int i = 0; i < n; i++){
            insert(nums[i], root);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = findMaxXor(nums[i], root);
            ans = max(ans, temp);
        }
        return ans;
    }
};
