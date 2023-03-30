# https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        count = 0
        i = 0
        ans = 0
        size = len(nums)
        while i < size:
            if nums[i] == 0:
                count += 1
                ans += count
            else:
                count = 0

            i += 1
            
        return ans