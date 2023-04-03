# https://leetcode.com/problems/boats-to-save-people/
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        l, r = 0, len(people)-1
        res = 0

        # each loop decides/adds exactly 1 boat
        # if people[l] (current lighter) + people[r] (current heaviest) <= limit: 1 boat with both
        # else: 1 boat with the heaviest

        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1

            r -= 1
            res += 1

        return res