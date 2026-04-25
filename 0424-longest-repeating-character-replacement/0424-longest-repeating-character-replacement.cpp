class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int l = 0;
        int maxFre = 0 ;
        int res = 0 ;
        for(int r = 0 ; r < s.length();r++)
        {
            count[s[r]]++;
            maxFre = max(maxFre , count[s[r]]);
            while((r - l +1) - maxFre > k)
            {
                count[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};