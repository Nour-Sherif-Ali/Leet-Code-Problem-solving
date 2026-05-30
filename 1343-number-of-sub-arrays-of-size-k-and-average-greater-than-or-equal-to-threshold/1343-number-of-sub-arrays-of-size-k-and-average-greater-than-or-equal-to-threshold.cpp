class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int count = 0 ;
        int l = 0;
        for(int r = 0; r < arr.size() ; r++)
        {
            sum += arr[r]; 
            if(r - l +1 == k)
            {
                if(sum >= threshold * k )
                {
                    count++;
                }
                  sum -=arr[l];
                  l++;
            }
            
          
        }
        return count;
    }
};