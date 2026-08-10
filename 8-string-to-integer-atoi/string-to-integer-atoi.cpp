class Solution {
public:
    int myAtoi(string s)
    {
        int n = s.size();

        if(n == 0) return 0;

        int i = 0;

        while(i<n && s[i] == ' ')
        {
            i++;
        }

        bool neg = false;
        long long ans = 0;

        if(i<n && s[i] == '-')
        {
            neg = true;
            i++;
        }

        else if(i<n && s[i] == '+') i++;
       

        while(i<n && s[i] >= '0' && s[i] <= '9')
        {
            int dig = s[i] - '0';

            ans = ans*10 + dig;

            if(neg == true)
            {
                long long check = -ans;
                if(check < INT_MIN) return INT_MIN;
            }

            else
            {
                if(ans > INT_MAX) return INT_MAX;
            }

            i++;
        }

        if(neg == true) ans = -ans;


        return ans;
    }
};