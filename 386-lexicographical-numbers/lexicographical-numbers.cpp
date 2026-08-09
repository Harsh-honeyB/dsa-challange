class Solution {
public:
    void solve(int curr, int n, vector<int>&result)
    {
        if(curr > n) return;

        result.push_back(curr);

        for(int a = 0; a<=9; a++)
        {
            int new_curr = (curr*10) + a;

            if(new_curr > n) return;
            
            solve(new_curr, n, result);
        }
    }
    vector<int> lexicalOrder(int n) 
    {
        vector<int>result;

        for(int i = 1; i<=9; i++)
        {
            solve(i, n, result);
        }

        return result;
        
    }
};