# https://leetcode.com/problems/longest-common-prefix/
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = len(min(strs, key=len))
        ans = ""

        for i in range(min_len):
            for s in strs:
                if s[i] != strs[0][i]:
                    return ans
            ans += s[i]
    
        return ans
