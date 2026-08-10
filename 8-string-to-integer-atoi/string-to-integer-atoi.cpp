class Solution {
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.size();

        while(i < n && s[i] == ' ')
        {
            i++;
        }

        bool neg = false;

        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-')
                neg = true;

            i++;
        }

        long long ans = 0;

        while(i < n && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            if(!neg && ans > INT_MAX)
                return INT_MAX;

            if(neg && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        if(neg)
            ans = -ans;

        return ans;
    }
};