class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& supplies) {
        unordered_map<string, vector<int>> adj;
        int n = recipes.size();
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < ing[i].size(); j++){
                if(st.count(ing[i][j]) == 0){
                    adj[ing[i][j]].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<string> q;
        vector<string> res;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(recipes[i]);
                res.push_back(recipes[i]);
            }
        }
        while(!q.empty()){
            string node = q.front();
            q.pop();
            for(auto& v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(recipes[v]);
                    res.push_back(recipes[v]);
                }
            }
        }
        return res;
    }
};
