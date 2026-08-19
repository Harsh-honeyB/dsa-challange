class Solution {
public:
    int n;
    int solve(vector<string>& words, int idx, unordered_map<char, int>&m1, unordered_map<char, int>&m2)
    {
        if(idx>=n) return 0;

        string str = words[idx];
        int sum = 0;
        unordered_map<char, int>temp;
        bool flag = true;
        for(int i = 0; i<str.length(); i++)
        {
            if(m1.find(str[i])!=m1.end() && m1[str[i]] > 0)
            {
                m1[str[i]]--;
                sum+=m2[str[i]];
                temp[str[i]]++;
            }

            else
            {
                flag = false;
                break;
            }
        }
        int ans1 = 0;
        if(flag == true)
        {
            ans1 = sum + solve(words, idx+1, m1, m2);

            for(auto it : temp)
            {
                m1[it.first] += it.second;
            }
            
        }

        else
        {
            for(auto it : temp)
            {
                m1[it.first] += it.second;
            }

        }

        int ans2 = 0 + solve(words, idx+1, m1, m2);
        return max(ans1, ans2);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        n = words.size();
        unordered_map<char, int>m1;
        
        for(int i = 0; i<letters.size(); i++)
        {
            m1[letters[i]]++;
        }

        unordered_map<char, int>m2;

        int i = 0;
        for(char ch = 'a'; ch<='z'; ch++)
        {
            m2[ch] = score[i];
            i++;
        }

        return solve(words, 0, m1, m2);

        

    }
};