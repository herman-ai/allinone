'''
Solve using finite state automata, where the current state
represents the current character
state 0 = [A-Z]
state 1 = [a-z]
state 2 = Space
state 3 = separator
state 4 = Terminal
'''

def is_capital(c):
    return ord(c) in range(ord('A'), ord('Z')+1)

def is_small(c):
    return ord(c) in range(ord('a'), ord('z')+1)

separators = {',', ';', ':'}
terminals = {'.', '?', '!', '‽'}
valid_transitions = {0: {1, 2},
                     1: {1, 2, 3, 4},
                     2: {0, 1},
                     3: {2},
                     4: None
                     }

def is_valid_transition(s1, s2):
    return s2 in valid_transitions[s1]

def get_state(c):
    if is_capital(c):
        return 0
    if is_small(c):
        return 1
    if c == ' ':
        return 2
    if c in separators:
        return 3
    if c in terminals:
        return 4


def check_valid(s):
    if not is_capital(s[0]):
        return False

    if s[-1] not in terminals:
        return False

    prev_state = 0
    i = 1

    for i in range(1, len(s)):
        new_state = get_state(s[i])
        if not is_valid_transition(prev_state, new_state):
            return False
        prev_state = new_state
    if new_state != 4:
        return False
    return True

if __name__ == "__main__":
    sentence = "Ivalid sentence‽"
    print(f"Is this a valid sentence {check_valid(sentence)}")