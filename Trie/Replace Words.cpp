class Solution {
public:

    struct trieNode{
        trieNode* children[26];
        bool endOfWord;
        string word;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        newNode->endOfWord = false;
        newNode->word = "";
        return newNode;
    }

    void insert(trieNode* root, string& str){
        trieNode* crawler = root;
        for(auto& ch : str){
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->word = str;
        crawler->endOfWord = true;
    }

    string findRoot(string& word, trieNode* root){
        trieNode* crawler = root;
        string res = "";
        for(auto& ch : word){
            int idx = ch - 'a';
            if(crawler->endOfWord){
                break;
            }
            if(crawler->children[idx] == NULL){
                return word;
            }
            res += ch;
            crawler = crawler->children[idx];
        }
        return res;
    }

    string replaceWords(vector<string>& dict, string s) {
        trieNode* root = getNode();
        for(auto& r : dict){
            insert(root, r);
        }
        string result = "";
        stringstream ss(s);
        string word;
        while(getline(ss, word, ' ')){
            result += findRoot(word, root) + " ";
        }
        result.pop_back();
        return result;
    }
};
