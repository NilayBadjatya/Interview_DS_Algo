typedef priority_queue<int, vector<int>, greater<int>> P;
class NumberContainers {
public:
    unordered_map<int, int> idxToNum;
    unordered_map<int, P> numToIdx;
    NumberContainers() {
    }
    
    void change(int index, int number) {    
        idxToNum[index] = number;
        numToIdx[number].push(index);
    }
    
    int find(int number) {
        if(numToIdx[number].size() == 0){
            return -1;
        }
        while(!numToIdx[number].empty()){
            int a = numToIdx[number].top();
            numToIdx[number].pop();
            if(idxToNum[a] == number){
                numToIdx[number].push(a);
                return a;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
