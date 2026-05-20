class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> results(temps.size());
        stack <int> st;
        for(int i=0; i<temps.size(); i++)
        {
            while(!st.empty() && temps[st.top()] < temps[i])
            {
                results[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return results;
    }
};