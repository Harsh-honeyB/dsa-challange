class Solution {
public:
    vector<int>solve(string s)
    {
        vector<int>result;

        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                vector<int>left = solve(s.substr(0, i));
                vector<int>right = solve(s.substr(i+1));

                for(auto x : left)
                {
                    for(auto y : right)
                    {
                        if(s[i] == '+')
                        {
                            result.push_back(x+y);
                        }
                        if(s[i] == '-')
                        {
                            result.push_back(x-y);
                        }
                        if(s[i] == '*')
                        {
                            result.push_back(x*y);
                        }
                    }
                }
            }
        }

        if(result.size() == 0)
        {
            result.push_back(stoi(s));
        }

        return result;
    }
    vector<int> diffWaysToCompute(string expression) 
    {
        return solve(expression);
        
    }
};