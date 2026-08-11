class Solution {
public:
    map<char, string>mp;
    vector<string>result;
    void solve(string &digits, int idx, string &temp)
    {
        if(idx >=digits.size())
        {
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string t = mp[ch];
        for(int i = 0; i<t.size(); i++)
        {
            temp.push_back(t[i]);
            solve(digits, idx+1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        int n = digits.size();
        string temp = "";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(digits, 0, temp);
        return result;
    }
};