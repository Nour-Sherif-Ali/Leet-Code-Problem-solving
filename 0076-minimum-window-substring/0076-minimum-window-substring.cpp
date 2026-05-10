class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char , int> countT;
        unordered_map<char , int> window;
        for(auto c : t){
            countT[c]++;
        }
        int have = 0 ;
        int need = countT.size();

        int left = 0;
        int minLen = INT_MAX;
        int start = 0 ;

        for(int r = 0 ; r < s.size(); r++ )
        {
            char c = s[r];
            window[c]++;
            if(countT.count(c) && window[c] == countT[c])
            {
                have++;
            }
            while(have == need)
            {
                int currentLen = r - left + 1;
                if(currentLen < minLen)
                {
                    minLen = currentLen;
                    start = left;
                }
                char leftChar = s[left];
                window[leftChar]--;
                if(countT.count(leftChar) && window[leftChar] < countT[leftChar])
                {
                    have--;
                }
                left++;
            }

        }
        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};