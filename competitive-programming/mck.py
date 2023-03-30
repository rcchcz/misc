class PrOP:
    def __init__(self, Piority, NextOP, Lvl):
        self.Piority = Piority
        self.NextOP = NextOP
        self.Lvl = Lvl
    
def nsort(L1: list[PrOP]) -> list[PrOP]:
    i = 0
    init_sort = L1
    while i < len(L1):
        if L1[i].NextOP != -1:
            next_op = L1[(L1[i].NextOP)-1]
            n0 = L1[i].Lvl
            n1 = next_op.Lvl
            if i+1 < len(L1):
                n2 = L1[i+1].Lvl
            else:
                n2 = -1
            # check dependency among OPs
            if n0 >= n1 and n1 >= n2:
                L1.pop((L1[i].NextOP)-1)
                L1.insert(i+1, next_op)
            # break dependency among OPs
            # return the unaltered list
            else:
                return init_sort
        i += 1
    return L1

# C1
# [1, 2, 4, 3]
'''
op1 = PrOP(1, -1, 2)
op2 = PrOP(2, 4, 2)
op3 = PrOP(3, -1, 2)
op4 = PrOP(4, -1, 2)
L1 = [op1, op2, op3, op4]
'''

# C2
# [1, 2, 4, 3, 6, 5]
'''
op1 = PrOP(1, -1, 2)
op2 = PrOP(2, 4, 2)
op3 = PrOP(3, -1, 2)
op4 = PrOP(4, -1, 2)
op5 = PrOP(5, -1, 2)
op6 = PrOP(6, 5, 2)
L1 = [op1, op2, op3, op4, op5, op6]
'''

# C3
# [1, 2, 4, 3, 5, 6]
'''
op1 = PrOP(1, -1, 2)
op2 = PrOP(2, 4, 2)
op3 = PrOP(3, -1, 2)
op4 = PrOP(4, -1, 2)
op5 = PrOP(5, -1, 2)
op6 = PrOP(6, 5, 1)
L1 = [op1, op2, op3, op4, op5, op6]
'''

# C4
'''
L1 = []
'''

# C4
'''
op1 = PrOP(1, -1, 2)
L1 = [op1]
'''

print("[INI]")
for i in range(len(L1)):
    print(L1[i].Piority)
print("[INI]")
print()

L2 = nsort(L1)  

print("[FIN]")
for i in range(len(L2)):
    print(L2[i].Piority)
print("[FIN]")