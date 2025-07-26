// Approach 1 : Using Trie
// Time Complexity - O(N^2)
class Solution {
public:
    struct Node{
        bool endOfWord;
        Node* children[26];
    };
    
    Node* getNode(){
        Node* newNode = new Node();
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        newNode->endOfWord = false;
        return newNode;
    }
    
    void insert(Node* root, string& s){
        Node* pCrawl = root;
        for(auto& ch : s){
            if(pCrawl->children[ch - 'a'] == NULL){
                pCrawl->children[ch - 'a'] = getNode();
            }
            pCrawl = pCrawl->children[ch - 'a'];
        }
        pCrawl->endOfWord = true;
    }
    
    string longestValidWord(vector<string>& words) {
        // code here
        Node* root = getNode();
        
        for(auto& s : words){
            insert(root, s);
        }
        
        string ans = "";
        for(auto& s : words){
            Node* pCrawl = root;
            bool flag = true;
            for(auto& ch : s){
                if(pCrawl->children[ch - 'a'] == NULL){
                    flag = false;
                    break;
                }
                pCrawl = pCrawl->children[ch - 'a'];
                if(pCrawl->endOfWord == false){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                if(ans.size() < s.size()){
                    ans = s;
                }else if(ans.size() == s.size()){
                    ans = min(ans, s);
                }
            }
        }
        return ans;
    }
};


// Approach 2 : Time Complexity - O(N^2)
class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        unordered_set<string> st(words.begin(), words.end());
        string ans = "";
        for(auto& s : words){
            string temp = "";
            bool f = true;
            for(int i = 0; i < s.size(); i++){
                temp += s[i];
                if(st.count(temp) == 0){
                    f = false;
                    break;
                }
            }
            if(f){
                if(ans.size() < s.size()){
                    ans = s;
                }else if(ans.size() == s.size()){
                    ans = min(ans, s);
                }
            }
        }
        return ans;
    }
};
