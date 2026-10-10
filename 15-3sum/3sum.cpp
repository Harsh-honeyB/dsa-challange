class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i = 0; i<n; i++)
        {
            int key = nums[i];
            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                if(key + nums[j] + nums[k] == 0)
                {
                    vector<int>temp = {key, nums[j], nums[k]};

                    st.insert(temp);

                    j++;
                    k--;
                }

                else if(j < k && nums[j] + nums[k] < (-1)*key) j++;
                else k--;
            }
        }

        ans.assign(st.begin(), st.end());
        return ans;        
    }
};