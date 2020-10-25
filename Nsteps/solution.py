'''
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

'''
from copy import deepcopy
from collections import Counter

def ways_to_climb(n, step_dist, steps={1,2}):
    rval = []
    if n==0:
        return [step_dist]  # We are done
    if n < 0:
        return None   # No possible way
    for step in steps:
        sd = deepcopy(step_dist)
        sd.append(step)
        _sd = ways_to_climb(n-step, sd, steps)
        if _sd is not None:
            rval.extend(_sd)
    return rval

if __name__ == "__main__":
    sd = ways_to_climb(4, [], steps={1,2})
    print(sd)
    print(f'Number of ways = {len(sd)}')
