class Solution {
public:
    vector<vector<int>>result;
    set<int>st;
    void solve(int idx, vector<int>& nums, vector<int>& temp)
    {
        if(temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++)
        {
            if(st.find(nums[i]) == st.end())
            {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(i+1, nums, temp);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int>temp;

        solve(0, nums, temp);

        return result;
        
    }
};