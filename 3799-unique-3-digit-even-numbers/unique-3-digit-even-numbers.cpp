class Solution {
public:
    int n;

    set<int> result;

    void solve(int idx, vector<int>& nums, string& temp, set<int>& st) {

        if(temp.size() == 3)
        {
            if(temp[0] != '0' && stoi(temp) % 2 == 0)
            {
                result.insert(stoi(temp));
            }

            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(st.find(i) == st.end())
            {
                temp.push_back(nums[i] + '0');
                st.insert(i);

                solve(i + 1, nums, temp, st);

                temp.pop_back();
                st.erase(i);
            }
        }
    }

    int totalNumbers(vector<int>& nums)
    {
        n = nums.size();

        string temp = "";
        set<int> st;

        solve(0, nums, temp, st);

        return result.size();
    }
};