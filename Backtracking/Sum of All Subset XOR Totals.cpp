//C++ Code
class Solution {
public:

    void backTrack(vector<int>& nums, int start, vector<int> tempList, vector<vector<int>>& list){
        list.push_back(tempList);
        for(int i = start; i < nums.size(); i++){
            tempList.push_back(nums[i]);
            backTrack(nums, i+1, tempList, list);
            tempList.pop_back();
        }
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> tempList;
        backTrack(nums, 0, tempList, list);
        int sum = 0;
        for(int i = 0; i < list.size(); i++){
            int temp = 0;
            for(auto& x : list[i]){
                temp ^= x;
            }
            sum += temp;
        }
        return sum;
    }
};

//JAVA Code
class Solution {

    private void backTrack(int[] nums, int start, List<Integer> tempList, List<List<Integer>> list){
        list.add(new ArrayList<>(tempList));
        for(int i = start; i < nums.length; i++){
            tempList.add(nums[i]);
            backTrack(nums, i+1, tempList, list);
            tempList.remove(tempList.size() - 1);
        }
    }

    public int subsetXORSum(int[] nums) {
        List<Integer> tempList = new ArrayList<>();
        List<List<Integer>> list = new ArrayList<>();
        backTrack(nums, 0, tempList, list);
        int sum = 0;
        for(List<Integer> subset : list){
            int temp = 0;
            for(int x : subset){
                temp ^= x;
            }
            sum += temp;
        }
        return sum;
    }
}
