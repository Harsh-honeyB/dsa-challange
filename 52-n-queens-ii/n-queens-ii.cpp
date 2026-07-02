class Solution {
public:
    int N;
    int count = 0;
    bool isValid(vector<string>&board, int row, int col)
    {
        // check up //

        for(int i = row - 1; i>=0; i--)
        {
            if(board[i][col] == 'Q') return false;
        }

        // check horizontal //

        for(int i = col; i<N;  i++)
        {
            if(board[row][i] == 'Q') return false;
        }

        // check left daigonal //
        for(int i = row - 1, j = col - 1; i>=0 && j>=0; i--,j--)
        {
            if(board[i][j] == 'Q') return false;
        }
        
        // check right daigonal //

        for(int i = row - 1, j = col + 1; i>=0 && j < N; i--,j++)
        {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(vector<string>&board, int row)
    {
        if(row >= N)
        {
            count++;
            return;
        }

        for(int col = 0; col<N; col++)
        {
            if(isValid(board, row, col) == true)
            {
                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.';
            }
        
        }
    }

    int totalNQueens(int n) 
    {
       

        N = n;
        vector<string>board(n, string(n, '.')); 
        // n = 4 -> {"....", "....", "....", "...."} jo string vector me jayega uski v length 4 hi hoga //
    

        solve(board, 0);

        return count;
        
    }
};