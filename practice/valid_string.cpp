/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
Input: "()[]{}
Output: true

Input: "(]"
Output: false

Input: "([)]"
Output: false
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
  
    char in[] = "([)]";
    int i = 0;
  
    stack<char> my_stack;
    bool done = false;
  
    //cout << my_stack.size() << endl;
  
    while (i<strlen(in) && !done) {
      //cout << "B" << my_stack.size() << " : " << in[i] << endl;
      if ((in[i] == '(') || (in[i] == '{') || (in[i] == '[')) {
        my_stack.push(in[i]);
      }
      else {
        if (my_stack.empty()) {
          done = true;
          break;
        }
        char mytop = my_stack.top();
        my_stack.pop();
        switch(in[i]) {
          case ')':
              if (!(mytop == '(')) {
                done = true;
                break;
              }
            break;
          case '}':
              if (!(mytop == '{')) {
                done = true;
                break;
              }
            break;
          case ']':
              if (!(mytop == '[')) {
                done = true;
                break;
              }
            break;
        }
      } // end of else
      i++;
    } // end of while
  
    if (!my_stack.empty()) {
      cout << "Not valid" << endl;
    } else {
      cout << " It is valid" << endl;
    }
    
    return 0;
}

