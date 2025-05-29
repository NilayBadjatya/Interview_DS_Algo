typedef long long ll;
class Solution {
public:

    struct trieNode{
        trieNode* left = NULL;
        trieNode* right = NULL;
        int count = 0;
    };

    void insert(trieNode* root, int num){
        trieNode* crawler = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(bit == 0){
                if(crawler->left == NULL){
                    crawler->left = new trieNode();
                }
                crawler = crawler->left;
                crawler->count++;
            }else{
                if(crawler->right == NULL){
                    crawler->right = new trieNode();
                }
                crawler = crawler->right;
                crawler->count++;
            }
        }
    }

    void remove(trieNode* root, int num){
        trieNode* crawler = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(bit == 0){
                crawler = crawler->left;
                crawler->count--;
            }else{
                crawler = crawler->right;
                crawler->count--;
            }
        }
    }

    int findMaxXorEle(trieNode* root, int num){
        trieNode* crawler = root;
        int ele = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(bit == 0){
                if(crawler->right != NULL && crawler->right->count > 0){
                    ele |= (1 << i);
                    crawler = crawler->right;
                }else if(crawler->left != NULL && crawler->left->count > 0){
                    crawler = crawler->left;
                }else{
                    break;
                }
            }else{
                if(crawler->left != NULL && crawler->left->count > 0){
                    ele |= (1 << i);
                    crawler = crawler->left;
                }else if(crawler->right != NULL && crawler->right->count > 0){
                    crawler = crawler->right;
                }else{
                    break;
                }
            }
        }
        return ele;
    }

    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        trieNode* root = new trieNode();
        int ans = 0, j = 0;
        for(int i = 0; i < n; i++){
            insert(root, nums[i]);
            while(j < i && (ll)nums[i] > 2LL * (ll)nums[j]){
                remove(root, nums[j]);
                j++;
            }
            int ele = findMaxXorEle(root, nums[i]);
            ans = max(ans, ele);
        }
        return ans;
    }
};
