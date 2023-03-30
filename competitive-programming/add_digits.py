# https://leetcode.com/problems/add-digits/
class Solution:
    def addDigits(self, num: int) -> int:
        # naive solution
        #while num > 9:
        #    temp = 0
        #    while num:
        #        temp += (num%10)
        #        num //= 10
        #    num = temp
        #return num

        # solution using mathematical pattern - O(1)
        if num == 0: return 0
        elif num % 9 == 0: return 9
        else: return num % 9