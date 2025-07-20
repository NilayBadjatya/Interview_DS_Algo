class Solution {
public:

    struct Node{
        string val;
        string subFolder;
        unordered_map<string, Node*> children;
    };

    Node* getNode(string val){
        Node* temp = new Node();
        temp->val = val;
        temp->subFolder = "";
        return temp;
    }

    void insert(Node* root, vector<string>& path){
        for(auto& folder : path){
            if(root->children.count(folder) == 0){
                root->children[folder] = getNode(folder);
            }
            root = root->children[folder];
        }
    }

    string populateNodes(Node* root, unordered_map<string,int>& subFolderMap){
        vector<pair<string, string>> path;
        for(auto& [childName, child] : root->children){
            string c = populateNodes(child, subFolderMap);
            path.push_back({childName, c});
        }
        sort(path.begin(), path.end());

        string completePath = "";
        for(auto& [childName, childPath] : path){
            completePath += "(" + childName + childPath + ")";
        }
        root->subFolder = completePath;
        if(!completePath.empty()){
            subFolderMap[completePath]++;
        }
        return completePath;
    }

    void removeDuplicates(Node* root, unordered_map<string,int>& subFolderMap){
        for(auto it = root->children.begin(); it != root->children.end(); ){
            string childName = it->first;
            Node* child = it->second;

            if(!child->subFolder.empty() && subFolderMap[child->subFolder] > 1){
                it = root->children.erase(it);
            }else{
                removeDuplicates(child, subFolderMap);
                it++;
            }
        }
    }

    void constructResult(Node* root, vector<string>& path, vector<vector<string>>& result){
        for(auto& [childName, child] : root->children){
            path.push_back(childName);
            result.push_back(path);
            constructResult(child, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("/");

        for(auto& path : paths){
            insert(root, path);
        }

        unordered_map<string, int> subFolderMap;
        populateNodes(root, subFolderMap);

        removeDuplicates(root, subFolderMap);

        vector<vector<string>> result;
        vector<string> path;
        constructResult(root, path, result);
        return result;
    }
};
