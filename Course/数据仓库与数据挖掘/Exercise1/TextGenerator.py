'''
Author: GUO Ziyao
Date: 4/28/2017
  Use Markov model of order K to generate a pseudo-random text of length M.
  First I read from input.txt and concate lines together to form a new line
which contians all the characters in this file.
  Traverse this line and use every K continuous character to form a string
as status of Markov model. For every status, I know the next character of it.
So I can add this character to status's dictionary to plus this character's
appear time by one.
  Onece finished this process, I got every status's next character's appear
times. So first input a string whose length is greater than or equals to K, 
and generate a text of length M.

  Generate detail:
  For every status generate a random integer whose maximum value is the sum
of this status's next characters' appear times. And traverse this status's
dictionary, use a value to count the sum of appear times, onece the value is
greater than of equals to the random integer I choose this character as next
character. Loop util all M characters are generated.
'''

import random


def add_status(status, character, map, total):
    """Add character to status's dictionary

    Add character to status's dictionary and plus total appear times by one.

    Args:
        status: The word of length K.
        character: The character after status.
        map: A dictionary whose key is status and value is a dictionary. For
            example(K = 3):
            
            {'hel' : {'o' : 1, 'l' : 2},
             'wor' : {'t' : 2, 'l' : 6}}

        total: A dictionary whose key is status and value is total appear times
            of this status's descendant characters.
    """
    
    if map.get(status) is None:
        map[status] = dict()

    total[status] = total.get(status, 0) + 1
    times = map[status]    # status's dictionary
    times[character] = times.get(character, 0) + 1


def train(line, k, map, total):
    """Initial status' dictionaries

    Traverse this line and use every k continuous character to form a string
    as status of Markov model. For every status add this character to status's 
    dictionary to plus this character's appear time by one.

    Args:
        line: A line contains all the characters in the file.
        k: The character after status.
        map: A dictionary whose key is status and value is a dictionary. For
            example(K = 3):
            
            {'hel' : {'o' : 1, 'b' : 2},
             'wor' : {'t' : 2, 'z' : 6, 'k' : 3}}

        total: A dictionary whose key is status and value is total appear times
            of this status's descendant characters.
    """
    # If go to the end, loop the string.
    # So just add first k + 1 characters to the end for convenience
    for i in range(k + 1):
        line += line[i]
    
    # Original length of line
    length = len(line) - k - 1
    i = 0
    
    while i < length:
        status = ''
        for j in range(k):
            status += line[i + j]
        status = status.lower()
        add_status(status, line[i + k].lower(), map, total)
        i += 1

        
def next(status, map, total):
    """Get next character

    Generate a random integer whose maximum value is total[status]. And
    traverse this status's dictionary, use a value to count the sum of 
    appear times, onece the value is greater than of equals to the random 
    integer, choose this character as next character.

    Args:
        status: The word of length K.
        map: A dictionary whose key is status and value is a dictionary. For
            example(K = 3):
            
            {'hel' : {'o' : 1, 'l' : 2},
             'wor' : {'t' : 2, 'l' : 6}}

        total: A dictionary whose key is status and value is total appear times
            of this status's descendant characters.

    Returns:
        Status's next character
    """
    # If status not exist just return space
    if total.get(status) is None:
        return ' '

    # The total appear times of descendant characters
    length = total[status]
    pos = 0
    next_pos = random.randint(0, length)
    times = map[status]
    for (character, num) in times.items():
        pos += num
        if pos >= next_pos :
            return character
    

def text_generate(string, map, total, k, m):
    """Generate text

    Use string as initial string to generate a pseudo-random text of length m

    Args:
        string: Initial word.
        map: A dictionary whose key is status and value is a dictionary. For
            example(K = 3):
            
            {'hel' : {'o' : 1, 'l' : 2},
             'wor' : {'t' : 2, 'l' : 6}}

        total: A dictionary whose key is status and value is total appear times
            of this status's descendant characters.
        k: Markov model of order k
        m: Generate a text of length
    """
    file = open('output.txt', 'a')
    # Need a string whose length is greater of equals to k as initial status
    if len(string) < k:
        file.write('===================================================\n')
        file.write('|Please give a word whose length is greater than %d.|\n' % k)
        file.write('===================================================\n')
    elif len(string) < m:
        i = len(string)
        while i < m:
            status = ''
            for j in range(k, 0, -1):
                status += string[i - j]
            status = status.lower()
            string += next(status, map, total)
            i += 1
    
    file.write('\n\n|================================================|\n')
    file.write('The text I generated is:\nvvvvvvvvvv\n' + string + '\n^^^^^^^^^^\n')


# For debug only
def debug(map):
    for x in map:
        print  '%r : ' %x + str(map.get(x).items())
    
    
K = 5  # Markov model of order K
M = 500  # Generate a text of length M

file = open('input.txt')
#file = open('test.txt') # text.txt is a small file which is much smaller than input.txt

# Concate lines together
line = ''
for eachLine in file:
    line += eachLine + '\n'

map = dict()
total = dict()

train(line, K, map, total)

text_generate('he', map, total, K, M)
text_generate('harry', map, total, K, M)
text_generate('hello', map, total, K, M)
text_generate('I think', map, total, K, M)



