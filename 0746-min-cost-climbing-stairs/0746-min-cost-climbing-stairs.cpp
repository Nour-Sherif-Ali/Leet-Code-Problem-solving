class Solution {
public:
    vector<int> memo ; 
    int solve(vector<int>& cost, int n )
    {
        if(n == 0 || n == 1) return 0 ; 
        if(memo[n] != -1) return memo[n];
        int oneStep = solve(cost , n-1) + cost[n-1] ; 
        int twoStep = solve(cost , n-2) + cost[n-2] ;

        return memo[n] = min(oneStep , twoStep) ;  
    }  
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size() ; 
      memo.assign(n+1, -1); 
      return solve(cost,n) ; 
    }
};