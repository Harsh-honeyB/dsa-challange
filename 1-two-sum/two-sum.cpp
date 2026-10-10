class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        unordered_map<int, int>mp;

        for(int i = 0; i<n; i++)
        {
            int key = target - nums[i];
            
            if(mp.find(key)!=mp.end())
            {
                return {mp[key], i};
            }

            else
            {
                mp[nums[i]] = i;
            }
        }

        return {-1,-1};
    }
};