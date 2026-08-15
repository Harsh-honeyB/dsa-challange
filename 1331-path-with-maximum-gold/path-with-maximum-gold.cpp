class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || i >=n || j < 0 || j >= m || grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;
        int maxi = 0;

        for(vector<int>&dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

           maxi = max(maxi, solve(grid, new_i, new_j));
        }

        grid[i][j] = temp;

        return maxi + temp;





    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();

        int maxgold = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j]!=0)
                {
                    maxgold = max(maxgold, solve(grid, i, j));
                }

            }
        }

        return maxgold;
        
    }
};