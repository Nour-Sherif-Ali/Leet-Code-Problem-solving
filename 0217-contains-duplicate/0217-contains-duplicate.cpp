class Solution {
public:
                    
    bool containsDuplicate(vector<int> nums) {
	unordered_set<int> dup;
	
	sort(nums.begin(), nums.end());  // [1,1,2,3]
	for (int i = 0; i < nums.size(); i++)
	{
		if (dup.count(nums[i]))
		{
			return true;
		}
		dup.insert(nums[i]);
	}
	return false;

}
    
};