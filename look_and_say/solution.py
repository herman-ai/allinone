'''
The "look and say" sequence is defined as follows: beginning with the term 1,
each subsequent term visually describes the digits appearing in the previous term.
The first few terms are as follows:

1
11
21
1211
111221

As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.
Given an integer N, print the Nth term of this sequence.
'''

from argparse import ArgumentParser

if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("N", type=int)
    args = parser.parse_args()
    # print(f"{args.N}")

    prev = None
    new_one = []
    for i in range(args.N):
        if prev is None:
            prev = [1]
            new_one = prev
            continue
        curr = prev[0]
        counter = 1
        new_one = []
        for j, val in enumerate(prev):
            if j==0:
                continue
            if val == curr:
                counter += 1
            else:
                new_one.extend([counter, curr])
                curr = val
                counter = 1
        new_one.extend([counter, curr])
        prev = new_one
    print(''.join([str(n) for n in new_one]))
