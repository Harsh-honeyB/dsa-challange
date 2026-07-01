class Solution {
public:
    vector<string>result;

    bool valid(string temp)
    {
        int x = temp.size();

        int count = 0;

        for(int i = 0; i<x; i++)
        {
            if(temp[i] == '(') count++;

            if(temp[i] == ')') count--;

            if(count < 0) break;
        }

        if(count == 0) return true;
        else return false;
    }
    void solve(int n, string temp)
    {
        if(temp.size() == 2*n)
        {
            if(valid(temp) == true)
            {
                result.push_back(temp);
            }

            return;
        }

        temp.push_back('(');
        solve(n, temp);
        temp.pop_back();
        
        temp.push_back(')');
        solve(n, temp);

    }
    vector<string> generateParenthesis(int n) 
    {
        string temp = "";
        solve(n, temp);

        return result;
        
    }
};