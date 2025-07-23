#include <bits/stdc++.h> 
class Trie{

    public:

    struct Node{
        Node* children[26];
        bool endOfWord;
        int countPrefix;
        int countEnd;
    };

    Node* getNode(){
        Node* newNode = new Node();
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        newNode->endOfWord = false;
        newNode->countPrefix = 0;
        newNode->countEnd = 0;
        return newNode;
    }

    Node* root = getNode();
    Trie(){
        // Write your code here.
    }

    void insert(string &word){
        Node* pCrawl = root;
        for(auto& ch : word){
            if(pCrawl->children[ch - 'a'] == NULL){
                pCrawl->children[ch - 'a'] = getNode();
            }
            pCrawl = pCrawl->children[ch - 'a'];
            pCrawl->countPrefix++;
        }
        pCrawl->endOfWord = true;
        pCrawl->countEnd++;
    }

    int countWordsEqualTo(string &word){
        Node* pCrawl = root;
        for(auto& ch : word){
            if(pCrawl->children[ch - 'a'] == NULL){
                return 0;
            }
            pCrawl = pCrawl->children[ch - 'a'];
        }
        return pCrawl->countEnd;
    }

    int countWordsStartingWith(string &word){
        Node* pCrawl = root;
        for(auto& ch : word){
            if(pCrawl->children[ch - 'a'] == NULL){
                return 0;
            }
            pCrawl = pCrawl->children[ch - 'a'];
        }
        return pCrawl->countPrefix;
    }

    void erase(string &word){
        Node* pCrawl = root;
        for(auto& ch : word){
            pCrawl = pCrawl->children[ch - 'a'];
            pCrawl->countPrefix--;
        }
        pCrawl->countEnd--;
    }
};
