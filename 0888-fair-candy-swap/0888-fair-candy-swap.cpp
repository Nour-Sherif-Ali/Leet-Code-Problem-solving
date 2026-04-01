class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        for(int a : aliceSizes){
            sumA += a ;
        }
        int sumB =0 ;
        for(int b : bobSizes){
            sumB += b;
        }
        unordered_set<int> bobSet;
        for(int x : bobSizes){
            bobSet.insert(x);
        }

        for(int z : aliceSizes)
        {
            int b = z + (sumB - sumA) /2;   
            if(bobSet.count(b))
            {
                return {z,b};
            }
        }
        return {};

    }
};