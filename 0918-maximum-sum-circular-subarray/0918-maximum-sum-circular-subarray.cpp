class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = nums[0];
        int curmax = nums[0];
        int maxsum = nums[0];
        int curmin = nums[0];
        int minsum = nums[0];
        for(int i = 1 ; i < nums.size(); i++)
        {
            int x = nums[i];
            totalsum += x;
            curmax = max(x , curmax + x);
            maxsum = max(maxsum , curmax);
            curmin = min(x, curmin + x);
            minsum = min(minsum, curmin);
        }
        if(maxsum < 0 )
        {
            return maxsum ; 
        }
        return max(maxsum , totalsum - minsum);
    }
};