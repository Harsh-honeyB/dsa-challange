class Solution {
public:
    int n;
    vector<vector<string>> result;

    bool isPalindrome(string &t) 
    {
        int l = 0;
        int r = t.size() - 1;
        while (l < r) 
        {
            if (t[l] != t[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string &s, int idx, vector<string>& temp)
    {
        if (idx == n)
        {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            string t = s.substr(idx, i - idx + 1);
            if (isPalindrome(t))
            {
                temp.push_back(t);
                solve(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        n = s.size();
        vector<string> temp;
        solve(s, 0, temp);
        return result;
    }
};