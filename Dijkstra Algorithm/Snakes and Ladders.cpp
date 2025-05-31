typedef pair<int, pair<int, int>> P;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int total = n * n;
        unordered_map<int, pair<int, int>> numToCord;
        map<pair<int, int>, int> cordToNum;
        int num = total, level = 0;
        if(n % 2 != 0){
            int val = total - n + 1;
            for(int j = 0; j < n; j++){
                numToCord[val] = {0, j};
                cordToNum[{0, j}] = val++;
            }
            num = total - n;
            for(int i = 1; i < n; i++){
                if(level % 2 == 0){
                    for(int j = 0; j < n; j++){
                        numToCord[num] = {i, j};
                        cordToNum[{i, j}] = num--;
                    }
                }else{
                    for(int j = n-1; j >= 0; j--){
                        numToCord[num] = {i, j};
                        cordToNum[{i, j}] = num--;
                    }
                }
                level++;
            }
        }else{
            for(int i = 0; i < n; i++){
                if(level % 2 == 0){
                    for(int j = 0; j < n; j++){
                        numToCord[num] = {i, j};
                        cordToNum[{i, j}] = num--;
                    }
                }else{
                    for(int j = n-1; j >= 0; j--){
                        numToCord[num] = {i, j};
                        cordToNum[{i, j}] = num--;
                    }
                }
                level++;
            }
        }
        vector<vector<int>> result(n, vector<int> (n, INT_MAX));
        result[n-1][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {n-1, 0}});
        while(!pq.empty()){
            int rolls = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            int val = cordToNum[{i, j}];
            for(int r  = 1; r <= 6; r++){
                if(val + r <= total){
                    int x = numToCord[val+r].first;
                    int y = numToCord[val+r].second;
                    int t = board[x][y];
                    if(board[x][y] != -1){
                        x = numToCord[t].first;
                        y = numToCord[t].second;
                    }
                    if(rolls+1 < result[x][y]){
                        result[x][y] = rolls+1;
                        pq.push({rolls+1, {x, y}});
                    }
                }else{
                    break;
                }
            }
        }
        if(n % 2 != 0){
            return result[0][n-1] == INT_MAX ? -1 : result[0][n-1];
        }
        return result[0][0] == INT_MAX ? -1 : result[0][0];
    }
};
