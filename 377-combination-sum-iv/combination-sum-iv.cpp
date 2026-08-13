class Solution {
public:
    int count = 0;
    int t[201][1001];
    int solve(int idx, vector<int>& nums, int target)
    {
        if(idx>=nums.size() || target < 0) return 0;
        if(target == 0)
        {
            return 1;
        }

        if(t[idx][target]!=-1) return t[idx][target];
        int take = solve(0, nums, target - nums[idx]);
        int notake = solve(idx+1, nums, target);

        return t[idx][target] = take + notake;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);

        

        
    }
};