class Solution {
public:
    int n;
    set<vector<int>> st;
    void solve(vector<int>& nums, int idx, vector<int>& temp)
    {
        if(idx >= n)
        {
            if(temp.size() >= 2) st.insert(temp);
            return;
        }

        if(temp.empty() || nums[idx] >= temp.back()) 
        {
            temp.push_back(nums[idx]);        
            solve(nums, idx + 1, temp);
            temp.pop_back();              
        }
        
        solve(nums, idx + 1, temp);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        n = nums.size();
        vector<int> temp;
        solve(nums, 0, temp);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};