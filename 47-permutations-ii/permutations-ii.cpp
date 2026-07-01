class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums, int idx, map<int,int>&mp, vector<int>&temp)
    {
        if(temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }
        //int key = nums[idx];
        for(auto &it : mp)
        {
            if(it.second > 0)
            {
                temp.push_back(it.first);
                mp[it.first]--;
                solve(nums,idx+1, mp, temp);
                temp.pop_back();
                mp[it.first]++;

            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,int>mp;
        vector<int>temp;
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]++;
        }

        solve(nums,0,mp,temp);
        return result;

        
    }
};