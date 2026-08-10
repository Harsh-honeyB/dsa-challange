class Solution {
public:
    int m;
    int n;
    int nonobstacles;
    int result;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    void find(int i, int j, vector<vector<int>>& grid, int count)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return;

        if(grid[i][j] == 2)
        {
            if(nonobstacles == count)
            {
                result++;
                return;
            }
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        for(vector<int> & dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            find(new_i, new_j, grid, count+1);
        }
        grid[i][j] = temp;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        nonobstacles = 0;
        result = 0;
        int start_idx = 0, last_idx = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 0) nonobstacles++;
                if(grid[i][j] == 1)
                {
                    start_idx = i;
                    last_idx = j;
                }
            }
        }
        nonobstacles = nonobstacles + 1;
        int count = 0;
        find(start_idx, last_idx, grid, count);
        return result; 
        
    }
};