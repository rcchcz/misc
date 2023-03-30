# https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cur, sofar, start = 0,0,0
        lookup = {}

        for i in range(len(s)):
            if s[i] not in lookup:
                cur += 1
            else:
                start = max(start, lookup[s[i]])
                cur = i - start
            lookup[s[i]] = i
            sofar = max(cur, sofar)
        
        return sofar