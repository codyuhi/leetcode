class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool greater = false;
        int i = 0;
        while(1){
            if(nums[i] == target){
                return i;
            }else if(!greater && target < nums[i]){
                return i;
            }else if(i == nums.size() -1){
                return i + 1;
            }
            i++;
        }
        return 0;
    }
};