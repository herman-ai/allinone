/*
Given a string, return the length of the longest palindromic subsequence in the string.

For example, given the following string:

MAPTPTMTPA
Return 7, since the longest palindromic subsequence in the string is APTMTPA. Recall that a subsequence of a string does not have to be contiguous!

Your algorithm should run in O(n^2) time and space.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int
get_max_pallindrome_subsequence_length (const string & s, int start, int end)
{
  if (start >= end)
    {
      return end - start + 1;
    }
  int not_includes_first =
    get_max_pallindrome_subsequence_length (s, start + 1, end);
  int includes_first = 1;
  int e = end;
  while (e > start)
    {
      if (s[e] == s[start])
	{
	  includes_first =
	    2 + get_max_pallindrome_subsequence_length (s, start + 1, e - 1);
	  break;
	}
      e--;
    }
  return max (not_includes_first, includes_first);
}

int
main ()
{
  string s = "MAPTPTMTPA";
  cout << "Size of string " << s.length () << endl;
  cout << get_max_pallindrome_subsequence_length (s, 0, s.size () - 1);

  return 0;
}

