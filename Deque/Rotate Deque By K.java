class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type == 1){
            while(k--){
                int x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            }
        }else{
            while(k--){
                int x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
        }
    }
};

// JAVA CODE

class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        // code here
        if(type == 1){
            while(k-- > 0){
                // int x = dq.back();
                // dq.pop_back();
                int x = dq.removeLast();
                dq.addFirst(x);
            }
        }else{
            while(k-- > 0){
                // int x = dq.front();
                // dq.pop_front();
                int x = dq.removeFirst();
                dq.addLast(x);
            }
        }
    }
}
