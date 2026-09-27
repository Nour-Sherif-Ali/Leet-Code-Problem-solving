class Solution {
public:
 
    int fib(int n) {
        vector<int> dp(n+1 , -1) ; 
        return solve(dp , n ) ; 
    }

    int solve(vector<int>& dp , int n )
    {
        if(n <= 1 ) return n ; 
        if(dp[n] != -1 ) return dp[n] ; 
        int answer = solve(dp , n-1 ) + solve(dp , n-2) ; 
        return dp[n] = answer ; 
    }
};