class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st ; 
        unordered_map<int,int> mp;
        vector<int> ans ; 
        for(int x : nums2)
        {
            while(!st.empty() && x > st.top())
            {
                mp[st.top()] = x ; 
                st.pop() ;
            }
            st.push(x);
        }
        for(int x : nums1)
        {
            if(mp.count(x))
            {
                ans.push_back(mp[x]);
            }
            else{
                ans.push_back(-1) ; 
            }
        }
        return ans ; 

    }
};