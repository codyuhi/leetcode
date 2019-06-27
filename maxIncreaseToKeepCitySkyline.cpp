class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> xMax, yMax;
        for(int i = 0; i < grid.size(); i++){
           int x = 0;
           int topX = 0;
           for(int j = 0; j < grid[i].size(); j++){
               x = grid[i][j];
               if(x > topX){
                   topX = x;
               }
           }
           cout << topX << endl;
           xMax.push_back(topX);
        }
        return 0;
    }
};