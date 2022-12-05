import numpy as np
import random as r

def split(sampleBalls, splitSize):
    for i in range(0, len(sampleBalls), splitSize):
        yield sampleBalls[i:i + splitSize]

# here the logic is always to work with three groups to find the heaviest
# two will be weighed and one will be left out
# if the heaviest group is on the scale, one of the plates will come down 
# if the heaviest group is off the scale, the two plates will be on the same level
# in both cases we know which group is heavier
def weighing(sampleBalls0, sampleBalls1):
    if np.sum(sampleBalls0) > np.sum(sampleBalls1):
        return 0
    elif np.sum(sampleBalls1) > np.sum(sampleBalls0):
        return 1
    else:
        return 2

# each 1 represents one of the 8 balls of the same weight
# the 5 represents the heaviest ball
# the goal is that the weighing always returns the 5, regardless of its position (that's why we use shuffle)
balls = [1, 1, 1, 1, 1, 1, 1, 1, 5]
r.shuffle(balls)

# part 1: find the heaviest trio
# divide the 9 balls into 3 groups of 3
firstThreeGroups = list(split(balls, 3))

# first weighing
res = weighing(firstThreeGroups[0], firstThreeGroups[1])

# part 2: find the heaviest ball from the heaviest trio
# divide the heaviest trio into 3 groups of 1
secondThreeGroups = list(split(firstThreeGroups[res], 1))
print("Heaviest trio: ", secondThreeGroups)

# second weighing
res = weighing(secondThreeGroups[0], secondThreeGroups[1])
print("Heaviest ball: ", secondThreeGroups[res])
