class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> xMax, yMax;
        int total = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int x = 0;
            int y = 0;
            int topX = 0;
            int topY = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                x = grid[i][j];
                if (x > topX)
                {
                    topX = x;
                }
                y = grid[j][i];
                if (y > topY)
                {
                    topY = y;
                }
            }
                xMax.push_back(topX);
                //cout << "Pushed back X " << topX << endl;
                yMax.push_back(topY);
                //cout << "Pushed back Y " << topY << endl;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(xMax[i] < yMax[j]){
                    total += xMax[i] - grid[i][j];
                    //cout << "Added " << xMax[i] - grid[i][j] << " to total" << endl;
                }else{
                    total += yMax[j] - grid[i][j];
                    //cout << "Added " << yMax[j] - grid[i][j] << " to total" << endl;
                }
            }
        }
        return total;
    }
};