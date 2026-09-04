class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n  = nums.size();
        stack<int>st;
        vector<int>right(n);
        right[0] = nums[0]; 
        st.push(nums[0]);
        for(int i = 1; i<n; i++)
            {
                if(st.top() < nums[i])
                {
                    st.pop();
                    st.push(nums[i]);
                    right[i] = nums[i]; 
                }
                else
                {
                    right[i] = st.top();
                }
            }
        vector<int>left(n);
        left[n-1] = nums[n-1];
        st.push(nums[n-1]);
        for(int i = n-2; i>=0; i--)
            {
                if(st.top() > nums[i])
                {
                    st.pop();
                    st.push(nums[i]);
                    left[i] = st.top(); 
                }
                else
                {
                    left[i] = st.top();
                }
            }
        int idx = -1;
        for(int i = 0; i<n; i++)
            {
                int diff = right[i] - left[i];
                if(diff <= k)
                {
                    idx = i;
                    break;
                }
            }
        return idx;
        
    }
};