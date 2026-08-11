class Solution {
public:
    // vector<vector<int>>result;
    set<vector<int>>st;
    void solve(vector<int>& nums, int target, int idx, vector<int>& temp)
    {
        if(target == 0)
        {
            st.insert(temp);
            return;
        }
        if(target < 0) return;
        for(int i = idx; i<nums.size(); i++)
        {
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, target - nums[i], i+1, temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, target, 0, temp);
        vector<vector<int>> result(st.begin(), st.end());
        return result;
     
        
    }
};