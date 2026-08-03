class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq ; 
       for(int s : stones)
       {
        pq.push(s) ; 
       }

       while(pq.size() > 1)
       {
            int n1 = pq.top() ; 
            pq.pop() ; 
            int n2 = pq.top() ; 
            pq.pop() ; 
            if(n2 < n1)
            {
                pq.push(n1 - n2 ) ; 
            }
       }
       pq.push(0) ; 
       return pq.top() ; 
    }
};