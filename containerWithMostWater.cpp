class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximum = 0;
        
        //two pointers solution
        int first = 0;
        int last = height.size() - 1;
        
        while (first < last) {
            //calculate area
            maximum = max( (min(height[first], height[last]) * (last - first)), maximum) ;        
            
            //move pointers
            if (height[first] < height[last]) first++;
            else last--;
        }
        
        return maximum;
    }
}; 