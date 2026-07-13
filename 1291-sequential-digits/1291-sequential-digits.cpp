class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result ; 
        string s = "123456789" ;
        for(int i = 2 ; i <= 9 ; ++i)
        {
            for(int start = 0 ; start < 10 - i ; ++start)
            {
                int x = stoi(s.substr(start , i )) ; 
                if(x >= low && x <= high)
                {
                    result.push_back(x);
                }
            }
        }
        return result ; 
    }
};