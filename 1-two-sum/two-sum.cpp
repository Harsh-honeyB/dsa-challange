class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        int n = arr.size();
        unordered_map<int, int>mp;
        for(int i = 0; i<n; i++)
        {
            int key = target - arr[i];
            if(mp.find(key)!=mp.end())
            {
                return {mp[key], i};
            }

            mp[arr[i]] = i;
        }
        return {-1,-1};
    }
};