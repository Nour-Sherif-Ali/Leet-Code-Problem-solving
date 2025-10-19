class Solution(object):
    def fairCandySwap(self, aliceSizes, bobSizes):
        sumA, sumB = sum(aliceSizes), sum(bobSizes)
        diff = (sumB - sumA) // 2
        bobSet = set(bobSizes)

        for x in aliceSizes:
            if x + diff in bobSet:
                return [x, x + diff]
