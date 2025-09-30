class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        Deque<Integer> dq = new ArrayDeque<>();
        for(int i = 0; i < n; i++){
            dq.addLast(nums[i]);
        }

        while(k-- > 0){
            int x = dq.removeLast();
            dq.addFirst(x);
        }

        int i = 0;
        while(!dq.isEmpty()){
            int x = dq.removeFirst();
            nums[i++] = x;
        }

    }
}
