class Solution {
public:
    int n;
    int count = 0;
    bool check(vector<int>& temp, int k)
    {
        int p = temp.size();

        for(int i = 0; i < p; i++)
        {
            for(int j = i + 1; j < p; j++)
            {
                if(abs(temp[i] - temp[j]) == k) return false;
            }
        }

        return true;
    }
    void solve(int idx, vector<int>& nums, vector<int>& temp, int k)
    {
        if(idx >= n)
        {
            if(temp.size()!=0 && check(temp, k) == true)
            {
                count++;
            }

            return;
        }

        temp.push_back(nums[idx]);

        solve(idx+1, nums, temp, k);

        temp.pop_back();

        solve(idx+1, nums, temp, k);


    }
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        n = nums.size();
        vector<int>temp;
        solve(0, nums, temp, k);

        return count;
        
    }
};