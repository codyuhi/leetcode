class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> xMax, yMax;
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
                cout << "Pushed back X " << topX << endl;
                yMax.push_back(topY);
                cout << "Pushed back Y " << topY << endl;
        }
        return 0;
    }
};