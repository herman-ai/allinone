# Given two strings string1 and string2,
# the task is to find the smallest substring in string1
# containing all characters of string2 efficiently.

'''
Input: string = “this is a test string”, pattern = “tist”
Output: Minimum window is “t stri”
Explanation: “t stri” contains all the characters of pattern.

Input: string = “geeksforgeeks”, pattern = “ork”
Output: Minimum window is “ksfor”
'''

'''
l1 = len(str)
l2 = len(pattern)


put pattern in a hashmap
loop through the string
  if(pattern is found in string)
    save the index of the position in the string
    loop through the rest of the string to compare it with the hashmap

    if more occurances found, imcrement the index
'''

from collections import Counter

def is_match(h1, h2):
  match = True
  for k,v in h1.items():
    if v > h2.get(k, 0):
      match = False
      break
  return match



if __name__ == "__main__":

  string = "this is a test string"
  pattern = "t"

  h1 = dict(Counter(pattern))

  start = 0
  end = 0
  h2 = {}
  soln = (999999, start, end)

  while end < len(string):
    # We guaranteed don't have a match
    while not is_match(h1, h2) and end < len(string):
      count = h2.get(string[end], 0)
      h2[string[end]] = count + 1
      end += 1

    # I am guaranteed to have a match
    while is_match(h1, h2):
      if string[start] in h2.keys() and start <= end:
        count = h2[string[start]]
        h2[string[start]] = count - 1
      start += 1

    # At this point, my match is broken by 1 character
    # which means that if I decrement my start, then I
    # will get back my match
    curr_len = soln[0]
    if end-start + 1 < curr_len:
      soln = (end - start + 1, start-1, end)

  print('shortest substring with full match is of length {}'.format(curr_len))
  start = soln[1]
  end = soln[2]
  print(string[start:end])





