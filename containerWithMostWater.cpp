class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = 0; j < height.size(); j++){
                if( i != j ){
                    if ( height[i] < height[j] ){
                        int tempMax = height[i] * abs(j - i);
                        if( tempMax > max ){
                            max = tempMax;
                        }
                    } else {
                        int tempMax = height[j] * abs(i - j);
                        if( tempMax > max ){
                            max = tempMax;
                        }
                    }
                }
            }
        }
        return max;
    }
};