class Solution {
public:
    bool solve(string s, string p)
    {
        if(p.size() == 0)
        {
            if(s.size() == 0)
            {
                return true;
            }

            return false;
            
        }

        bool flag = false;
        if(s.size() > 0 && (s[0] == p[0] || p[0] == '.'))
        {
            flag = true;
        }

        if(p.size() > 1 && p[1] == '*')
        {
            bool dtake = solve(s, p.substr(2));
            bool take = flag && solve(s.substr(1), p);

            return (dtake || take);
        }

        return flag && solve(s.substr(1), p.substr(1));
    }

    bool isMatch(string s, string p) 
    {
        return solve(s, p);

        
    }
};