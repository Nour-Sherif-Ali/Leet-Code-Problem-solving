class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1) return;

        char first = s.front();
        char last = s.back();

        s.erase(s.begin()); 
        s.pop_back();

        reverseString(s);

        s.insert(s.begin(), last);
        s.push_back(first);

        
    }
};