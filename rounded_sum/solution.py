import math

inp = [1.9, 2.8, 3.1, 6.1, 9.8]
inp = sorted(inp, key=lambda x:x-math.floor(x))
print(inp)
rounded_sum = round(sum(inp))
base_sum = sum([math.floor(i) for i in inp])
remainder = rounded_sum - base_sum
for i in range(len(inp)-1, -1, -1):
    if len(inp)-i <= remainder:
        inp[i] = math.ceil(inp[i])
    else:
        inp[i] = math.floor(inp[i])
print(inp)