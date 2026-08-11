class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&v, int idx, int k, vector<int>&temp)
    {
        if(k==0)
        {
            result.push_back(temp);
            return;
        }
        
        if(idx == v.size()) return;

        // temp.push_back(v[idx]);
        // solve(v, idx+1, k-1, temp);
        // temp.pop_back();
        // solve(v, idx+1, k, temp);
        for(int i = idx; i<v.size(); i++)
        {
            temp.push_back(v[i]);
            solve(v, i+1, k-1, temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>v;
        for(int i = 1; i<=n; i++)
        {
            v.push_back(i); 
        }
        // 1 2 3 4 // 
        vector<int>temp; 
        solve(v, 0, k, temp);
        return result;

        
    }
};