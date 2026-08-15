class Solution {
public:
    int n;
    int miniscore = INT_MAX;
    vector<int>result;
    void solve(vector<int>& nums, vector<int>&perm, vector<bool>&visited, int score)
    {
        if(score > miniscore) return;
        if(perm.size() == n)
        {
            score+=abs(perm.back() - nums[perm[0]]);
            if(score < miniscore)
            {
                miniscore = score;
                result = perm;
            }

            return;
        }


        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                perm.push_back(i);
                int s = perm.size();
                solve(nums, perm, visited, score + abs(perm[s-2] - nums[perm[s-1]]));

                visited[i] = false;
                perm.pop_back();
            }
        }
    }
    vector<int> findPermutation(vector<int>& nums) 
    {
        n = nums.size();
        vector<bool>visited(n, false);
        vector<int>perm = {0};
        visited[0] = true;
        int score = 0;
        solve(nums,perm, visited, score);

        return result;
        
    }
};