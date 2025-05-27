class Solution {
public:
    struct trieNode {
        bool endOfWord;
        trieNode* children[26];
        string word;
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->word = "";
        return newNode;
    }

    void insert(trieNode* root, string& str) {
        trieNode* crawler = root;
        for (auto& ch : str) {
            if (crawler->children[ch - 'a'] == NULL) {
                crawler->children[ch - 'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->endOfWord = true;
        crawler->word = str;
    }

    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void DFS(vector<vector<char>>& board, int i, int j, trieNode* root, int m,
             int n, vector<string>& result) {
        if (i >= m || i < 0 || j < 0 || j >= n || board[i][j] == '$' ||
            root->children[board[i][j] - 'a'] == NULL) {
            return;
        }
        root = root->children[board[i][j] - 'a'];
        if (root->endOfWord == true) {
            result.push_back(root->word);
            root->endOfWord = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for (auto& v : dir) {
            int x = i + v[0];
            int y = j + v[1];
            DFS(board, x, y, root, m, n, result);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        trieNode* root = getNode();
        for (auto& word : words) {
            insert(root, word);
        }

        vector<string> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (root->children[board[i][j] - 'a'] != NULL) {
                    DFS(board, i, j, root, m, n, result);
                }
            }
        }
        return result;
    }
};
