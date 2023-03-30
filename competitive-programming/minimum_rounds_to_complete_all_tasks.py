# https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        t = collections.Counter(tasks)
        nr = 0

        for x in t.values():
            if x == 1:
                return -1
            nr += (x + 2) // 3
        
        return nr
