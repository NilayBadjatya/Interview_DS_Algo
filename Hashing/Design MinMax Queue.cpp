class SpecialQueue {

  public:
    queue<int> q;
    map<int, int> mp;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        mp[x]++;
    }

    void dequeue() {
        // Remove element from the queue
        int x = q.front();
        q.pop();
        mp[x]--;
        if(mp[x] == 0){
            mp.erase(x);
        }
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return mp.begin()->first;
    }

    int getMax() {
        // Get maximum element
        return mp.rbegin()->first;
    }
};
