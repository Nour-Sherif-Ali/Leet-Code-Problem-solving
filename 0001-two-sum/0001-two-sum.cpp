class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
         unordered_map<int,int> seen;
         for(int i =0; i < v.size() ; i++)
         {
            int com = target - v[i];
            if(seen.count(com)){
                return {seen[com], i };
            }
            seen[v[i]] = i ;
         }
         return {};
    }
};