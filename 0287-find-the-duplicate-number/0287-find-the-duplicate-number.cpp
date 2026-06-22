class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen ; 
        int found = 0 ; 
        for(int r = 0 ; r < nums.size() ; r++)
        {
            if(seen.count(nums[r]))
            {
                found = nums[r];
            }
            seen.insert(nums[r]);
        }
        return found ; 
    }
};