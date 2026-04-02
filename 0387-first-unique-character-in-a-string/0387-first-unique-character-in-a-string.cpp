class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char , int> seen;
        for(auto x : s){
            seen[x]++;
        }
        for(int i = 0 ; i < s.size() ; i++ ){
            if(seen[s[i]] == 1 )
            {
                return i;
            }

        }
        return -1;
        
    }
};