class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int Sum = 0 ;
       for(int n : nums)
       {
         Sum += n ; 
         ans = max(ans , Sum) ;
         Sum = max(Sum , 0) ; 
       }
       return ans ; 
    }
};