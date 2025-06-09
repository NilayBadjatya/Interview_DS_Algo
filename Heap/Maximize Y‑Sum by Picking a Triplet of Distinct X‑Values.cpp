typedef pair<int, int> P;
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = y.size();
        priority_queue<P> pq;
        for(int i = 0; i < n; i++){
            pq.push({y[i], i});
        }
        int sum = 0, count = 0;
        unordered_set<int> st;
        while(!pq.empty() && count < 3){
            int val = pq.top().first;
            int idx = pq.top().second;
            if(st.count(x[idx]) == 0){
                sum += val;
                count++;
                st.insert(x[idx]);
            }
            pq.pop();
        }
        if(count != 3) return -1;
        return sum;
    }
};


//JAVA CODE

/* 
In Java, a comparator must return an int:

Negative → means "a should come before b"
Zero → means "a and b are equal in order"
Positive → means "b should come before a"
| Comparator    | Behavior |
| ------------- | -------- |
| `a[0] - b[0]` | Min-heap |
| `b[0] - a[0]` | Max-heap |



| Language | Function    | Description                        |
| -------- | ----------- | ---------------------------------- |
| C++      | `pq.top()`  | Peek at the top element            |
| C++      | `pq.pop()`  | Remove the top element             |
| Java     | `pq.peek()` | Peek at the top element            |
| Java     | `pq.poll()` | Get **and remove** the top element |

| Language | Method       | Behavior                                |
| -------- | ------------ | --------------------------------------- |
| C++      | `pq.push()`  | Always adds the element                 |
| Java     | `pq.offer()` | Adds element, returns `true` or `false` |
| Java     | `pq.add()`   | Adds element, but throws on failure     |


 */

class Solution {
    public int maxSumDistinctTriplet(int[] x, int[] y) {
        int n = x.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0])
                return b[0] - a[0];
            return b[1] - a[1];
        });
        for (int i = 0; i < n; i++) {
            pq.offer(new int[] { y[i], i });
        }

        int sum = 0, count = 0;
        Set<Integer> seen = new HashSet<>();
        while (!pq.isEmpty() && count < 3) {
            int[] top = pq.poll();
            int val = top[0];
            int idx = top[1];
            if (!seen.contains(x[idx])) {
                sum += val;
                count++;
                seen.add(x[idx]);
            }
        }
        if (count != 3) {
            return -1;
        }
        return sum;
    }
}
