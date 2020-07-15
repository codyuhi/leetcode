class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator itr = nums.begin();
        itr = find(nums.begin(), nums.end(), target);
        if(itr != nums.end()){
            return distance(nums.begin(), itr);
        }else{
            for(int i = 0; i < nums.size(); i++){
                if(target < nums[i]){
                    return i;
                }else if(i == nums.size() - 1){
                    return i + 1;
                }
            }
            return nums.size();
        }
    }
};