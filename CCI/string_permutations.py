# Design an algorithm to print all permutations of a string. For simplicity,
# assume all characters are unique.

'''
BREAKING DOWN THE PROBLEM:
We're going to use a technique called Base Case and Build, where we solve the
problem first for a simple base case (ie, n=0 or n=1), then build our way up
until we are faced with an "interesting" case (usually n=3 or n=4). This
technique generally leads to recursive solutions.

N=1
P('a') --> ['a']

N=2
P('ab') --> ['ab', 'ba']

N=3
Okay, here's a less trivial, more interesting case. 
Instead of writing out all the permutations by hand, let's see if we can find a
systematic solution, somehow using the results from N=2.

From N=2, we have two permutations: 'ab' and 'ba'. Now, we're introduced with a
new character 'c'. THAT'S THE ONLY DIFFERENCE from the previous case. Let's
take the two permutations 'ab' and 'ba' and insert 'c' everywhere possible:
'ab' --> ['cab', 'acb', 'abc']
'ba' --> ['cba', 'bca', 'bac']

We now have every possible permutation of 'abc':
['cab', 'acb', 'abc', 'cba', 'bca', 'bac']

So where S is the string, and N is the size of the string, the algorithm is:
If N==1: P(N)=S.
Otherwise, insert S[-1] into each slot of each permutation of P(N-1).

SOME CONSIDERATIONS:
The implementation is relatively trivial; it's just a simple recursive function.

COMPLEXITY:
The amount of permutations in P(N) is N!.
So, our char insertion must happen for each perm list: (N-1)! + (N-2)! + ... + 1
T = O((2n)!)

There are invariablly N stack frames in this recursive call so:
S = O(n)
'''


def insert_char_into_perms(c, l):
    '''
    Helper function for perms(s)

    Takes a list of permutations, and returns a list of new permutations, by
    adding a new character in each slot of each of the permutations.
    '''
    new_perms = []
    for perm in l:
        for spot in range(len(perm) + 1):
            new_perms.append(perm[:spot] + c + perm[spot:])
    return new_perms

def perms(s):
    ''' Takes a string, and returns a list of all it's permutations. '''
    if len(s) == 0: return [] # edge case

    if len(s) == 1: return [s]
    else: return insert_char_into_perms(s[-1], perms(s[0:-1]))

def perms_iterative(s):
    if len(s) == 0: return []
    if len(s) == 1: return [s]

    permlist = [s[0]]
    for c in s[1:]:
        newperms = []
        for perm in permlist:
            for spot in range(len(perm) + 1):
                newperms.append(perm[:spot] + c + perm[spot:])
        permlist = newperms
    return newperms

'''
if __name__ == "__main__":
    from timeit import Timer

    # first argument is the code to be run, the second "setup" argument is only run once,
    # and it not included in the execution time.
    t = Timer("""perms_iterative('abcdefgh')""",
              setup="""from string_permutations import perms_iterative""")

    t2 = Timer("""perms('abcdefgh')""",
               setup="""from string_permutations import perms""")

    print "Iterative: ", t.timeit(1000)
    print "Recursive: ", t2.timeit(1000)
'''
