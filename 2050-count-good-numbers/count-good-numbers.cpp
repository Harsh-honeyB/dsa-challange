class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b)
    {
        if(b == 0)
            return 1;

        long long half = power(a, b / 2);

        half = (half * half) % MOD;

        if(b % 2 == 1)
            half = (half * a) % MOD;

        return half;
    }

    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = power(5, even);
        ans = (ans * power(4, odd)) % MOD;

        return ans;
    }
};