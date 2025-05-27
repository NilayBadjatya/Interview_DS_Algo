class Trie {
public:

    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
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

    trieNode* root;

    Trie() {
        root = getNode();
    }

    void insertInTrie(trieNode* root, string& str){
        trieNode* crawler = root;
        for(auto& ch : str){
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch - 'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->endOfWord = true;
        crawler->word = str;
    }
    
    void insert(string word) {
        insertInTrie(root, word);
    }
    
    bool search(string word) {
        int n = word.size();
        int i = 0;
        trieNode* crawler = root;
        while(i < n){
            if(crawler->children[word[i] - 'a'] == NULL){
                return false;
            }
            crawler = crawler->children[word[i] - 'a'];
            i++;
        }
        
        return crawler->word == word;
    }
    
    bool startsWith(string word) {
        int n = word.size();
        int i = 0;
        trieNode* crawler = root;
        while(i < n){
            if(crawler->children[word[i] - 'a'] == NULL){
                return false;
            }
            crawler = crawler->children[word[i] - 'a'];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
