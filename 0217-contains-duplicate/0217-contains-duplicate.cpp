class Solution {
public:
                    
    bool containsDuplicate(vector<int> nums) { // [1,2,3,1]  1 =2 , 2 =1 , 3 =1 
	unordered_set<int> dup ; 
    
    for(int i = 0 ; i < nums.size() ; i++)
    { 
        if(dup.count(nums[i]))
        {
            return true ; 
        }
        dup.insert(nums[i]);   
    }
    return false;

}
    
};