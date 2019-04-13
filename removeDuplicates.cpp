class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(empty(nums))
            return 0;
        int w = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[w-1]!=nums[i]){
                nums[w++] = nums[i];
            }
        }
        return w;
    }
};