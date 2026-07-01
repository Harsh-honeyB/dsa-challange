class Solution {
  public:
    vector<string>result;
    int n,m;
    void solve(vector<vector<int>>& maze, int i, int j, string&temp)
    {
        
        
        if(i == n-1 && j == m-1) 
        {
            result.push_back(temp);
            return;
        }
        
        if(i<0 || i>=n || j<0 || j>=m || maze[i][j] == 0) return;
        
        maze[i][j] = 0;
        temp.push_back('D');
        solve(maze, i+1, j, temp);
        temp.pop_back();
        
        temp.push_back('L');
        solve(maze, i, j-1, temp);
        temp.pop_back();
        
        temp.push_back('R');
        solve(maze, i, j+1, temp);
        temp.pop_back();
        
        temp.push_back('U');
        solve(maze, i-1, j, temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) 
    {
        n = maze.size();
        m = maze[0].size();
        string temp = "";
        if(maze[0][0] == 0) return {};
        solve(maze, 0, 0, temp);
        return result;
        
    }
};