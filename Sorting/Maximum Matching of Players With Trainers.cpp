class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = players.size();
        int m = trainers.size();
        int i = 0, j = 0, matchings = 0;
        while(i < n && j < m){
            if(players[i] <= trainers[j]){
                matchings++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return matchings;
    }
};
