# https://leetcode.com/problems/search-insert-position/
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        nums.append(float('inf'))
        l, r = 0, len(nums)-1

        while l < r:
            mid = (l + r) // 2
            if target <= nums[mid]:
                r = mid
            else:
                l = mid + 1
        
        return l