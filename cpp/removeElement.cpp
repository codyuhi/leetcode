class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator itr = find(nums.begin(), nums.end(), val);
        while(itr != nums.end()){
            nums.erase(itr);
            itr = find(nums.begin(), nums.end(), val);
        }
        return nums.size();
    }
};