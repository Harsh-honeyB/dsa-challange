class Solution {
public:
    vector<vector<int>>result;
    int n;
    void solve(int idx, vector<int>& candidates, vector<int>& temp, int target)
    {
        if(idx >=n) return;
        
        if(target < 0) return;
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }

        for(int i = idx; i<n; i++)
        {
            temp.push_back(candidates[i]);
            target = target - candidates[i];
            solve(i, candidates, temp, target);
            temp.pop_back();
            target = target + candidates[i];

        }
            


        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        n = candidates.size();
        vector<int>temp;

        solve(0, candidates, temp, target);

        return result;
        
    }
};