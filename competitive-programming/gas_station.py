# https://leetcode.com/problems/gas-station/
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        maxlen = 0
        tank = 0

        for i in range(2*n):
            tank += (gas[i%n] - cost[i%n])
            if tank >= 0:
                maxlen += 1
            else:
                maxlen = 0
                tank = 0
        
        if maxlen >= n:
            return (2*n) - maxlen
        else:
            return -1