class Solution {
public:
    int lengthOfLongestSubstring(string s) {   //abcabcbb   //abc -> 3
     unordered_set<char> set;
     int l = 0 ; 
     int maxLen = 0 ;
     for(int r = 0 ; r < s.length(); r++)
     {
        while(set.count(s[r]))
        {
            set.erase(s[l]);
            l++;
        }
        set.insert(s[r]);
        maxLen = max(maxLen , r - l + 1);
      
    }
    return maxLen; 
}
};