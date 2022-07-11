# https://leetcode.com/problems/two-sum/
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lib = {}
        for i, n in enumerate(nums):
            if n in lib:
                return [lib[n], i]
            lib[target - n] = i
        return []
