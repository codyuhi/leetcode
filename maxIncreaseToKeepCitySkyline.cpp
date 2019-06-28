class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> xMax, yMax;
        for (int i = 0; i < grid.size(); i++)
        {
            int x = 0;
            int topX = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                x = grid[i][j];
                if (x > topX)
                {
                    topX = x;
                }
            }
            //cout << topX << endl;
            //if(i == 0){
                xMax.push_back(topX);
                cout << "Pushed back " << topX << endl;
            //}
        }
        for(int i = 0; i < grid.size(); i++){
            int y = 0;
            int topY = 0;
            for(int j = 0; j < grid.size(); j++){
                y = grid[j][i];
                if(y > topY){
                    topY = y;
                }
            }
            yMax.push_back(topY);
            cout << "pushed back " << topY << endl;
        }
        return 0;
    }
};