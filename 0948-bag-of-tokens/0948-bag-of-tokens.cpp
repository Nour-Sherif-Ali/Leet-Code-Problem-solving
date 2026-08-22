class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       int n = tokens.size() ; 
       int maxScore = 0, score = 0 ; 
       int i = 0 , j = n - 1; 
       sort(tokens.begin() , tokens.end()) ; 
       while(i <= j)
       {
            if(power >= tokens[i])
            {
                power -= tokens[i]; 
                score += 1;
                i++;
                maxScore = max(maxScore, score) ; 
            }
            else if(score >= 1)
            {
                power += tokens[j];
                score -= 1; 
                j--; 
            }
            else{
                return maxScore;
            }
        }
        return maxScore ; 
        
    }
};