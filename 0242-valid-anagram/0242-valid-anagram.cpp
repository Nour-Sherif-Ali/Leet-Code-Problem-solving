class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length() ) return false ; 
        unordered_map<char , int> s_word ; 
        unordered_map<char , int> t_word ;
        for(auto it : s)
        {
            s_word[it]++;
        } 
        for(auto it : t)
        {
            t_word[it]++;
        } 
        if(s_word == t_word) return true;
        
        return false ; 
    }
};