#https://leetcode.com/problems/longest-common-prefix/
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = len(min(strs, key=len))
        ans = ""
        pos = 0

        for i in range(min_len - 1):
            for s in strs:
                if s[i] != strs[0][pos]:
                    return ans
            ans += s[i]
            i += 1
            pos = i
    
        return ans