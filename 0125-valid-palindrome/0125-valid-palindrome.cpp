class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for(auto c : s)
        {
            if(isalnum(c)){
                newStr += tolower(c);
            }
        }
        string reverseString = newStr;
        reverse(reverseString.begin(), reverseString.end());
        return newStr == reverseString ;
    }
};