class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> possible;
        vector<int> vertices;
        vector<int> submit;
        bool finished = false;
        for(int i = 0; i < nums.size(); i++){
                possible.push_back(nums[i]);
                vertices.push_back(i);
        }
        for(int i = 0; i < possible.size(); i++){
            for(int j = 0; j < possible.size(); j++){
                if(i != j && !finished){
                    if(possible[i]+possible[j] == target){
                        submit.push_back(vertices[i]);
                        submit.push_back(vertices[j]);
                        finished = true;
                    }
                }
            }
        }
        return submit;
    }
};