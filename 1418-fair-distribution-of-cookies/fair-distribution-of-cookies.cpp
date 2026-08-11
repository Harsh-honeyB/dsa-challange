class Solution {
public:
    int n; 
    int result = INT_MAX;
    void solve(int idx, vector<int>& cookies, vector<int>&curr, int k)
    {
        if(idx >=n)
        {
            int maxi = INT_MIN;
            for(int i = 0; i<k; i++)
            {
                maxi = max(maxi, curr[i]);
            }
            result = min(result, maxi);
            return;
        }

        int cook = cookies[idx];
        for(int i = 0; i<k; i++)
        {
            curr[i]+=cook;
            solve(idx+1, cookies, curr, k);
            curr[i]-=cook;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        n = cookies.size();

        vector<int>curr(k,0);

        solve(0, cookies, curr, k);

        return result;

        
    }
};