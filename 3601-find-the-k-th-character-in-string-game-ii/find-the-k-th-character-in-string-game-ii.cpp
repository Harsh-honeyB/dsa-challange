class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) 
    {
        int n = operations.size();
        if(k == 1) return 'a';
        long long len = 1;
        int opr = -1;
        long long  mid = -1;
        for(int i = 0; i<n; i++)
        {
            len = len*2;

            if(len >= k)
            {
                mid = k - len/2;
                opr = operations[i];
                break;
            }
        }

        char ch = kthCharacter(mid, operations);

        if(opr == 0)
        {
            return ch;
        }

        else
        {
            if(ch == 'z') return 'a';
            else return ch+1;
        }
    }
};