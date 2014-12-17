'''
A k-palindrome is a string which transforms into a palindrome on removing at
most k characters. 

Given a string S, and an integer K, print "YES" if S is a k-palindrome;
otherwise print "NO". 

Constraints: 
S has at most 20,000 characters. 
0<=k<=30 

Test Cases:
abxa 1 --> YES
abdxa 1 --> NO

http://www.careercup.com/question?id=6287528252407808
'''

def k_palindrome_is_possible(s, k):
    '''
    The algorithm starts a forward-moving pointer at the 0th character, and a
    backward-moving pointer at the last character.

    At the start of each iteration, we know how many characters we've had to
    remove so far. 
    
    During each iteration, we find out if both s[p1] and s[p2] should be removed
    or if one of the two is a character we want to keep. If one side has a
    wanted character, we count the other side's unwanted characters until we find
    the wanted character's match.

    At the end of each iteration, if we have exceeded our limit of characters we
    can remove, we return False.

    At the end of all iterations, we have not exceeded the number of characters
    we can remove, and both pointers have passed each other, meaning we have
    confirmed a palindrome with at least k removals.
    '''
    if (len(s) < 2):
        return True
    else:
        p1 = 0
        p2 = len(s) - 1

        while (p1 <= p2):
            # check for a mismatch
            if (s[p1] != s[p2]):
                # now we must find which of the two chars we should remove
                against_p2 = p1 + 1
                against_p1 = p2 - 1

                to_remove = 0
                while True:
                    # a character that must be removed
                    to_remove += 1

                    # check if we've exhausted possible matches for both the
                    # mismatched characters
                    if (against_p2 > against_p1):
                        # these two must be removed! (p1 and p2)
                        # forget about our to_remove count.
                        # we must however account for adjacent elements, where
                        # we only have to remove one to make the substr size 2 a
                        # palindrome.
                        to_remove = min(2, p2 - p1) 
                        break

                    # is p1 matched yet?
                    if (s[p1] == s[against_p1]):
                        p2 = against_p1
                        break
                    # is p2 matched yet?
                    elif (s[p2] == s[against_p2]):
                        p1 = against_p2
                        break
                    # neither is matched
                    else:
                        against_p1 -= 1
                        against_p2 += 1

                k -= to_remove
                if (k < 0): return False

            p1 += 1
            p2 -= 1

    return True


if (__name__ == '__main__'):
    assert(k_palindrome_is_possible('', 0) == True)
    assert(k_palindrome_is_possible('', 5) == True)
    assert(k_palindrome_is_possible('x', 0) == True)
    assert(k_palindrome_is_possible('x', 1) == True)
    assert(k_palindrome_is_possible('aa', 1) == True)
    assert(k_palindrome_is_possible('ba', 1) == True)
    assert(k_palindrome_is_possible('ba', 0) == False)
    assert(k_palindrome_is_possible('aba', 0) == True)
    assert(k_palindrome_is_possible('aba', 1) == True)
    assert(k_palindrome_is_possible('abxa', 1) == True)
    assert(k_palindrome_is_possible('abdxa', 1) == False)
    assert(k_palindrome_is_possible('abcde', 4) == True)
    assert(k_palindrome_is_possible('abcde', 5) == True)
    assert(k_palindrome_is_possible('abcdefgfedcba', 0) == True)
    assert(k_palindrome_is_possible('abcdefggfedcba', 0) == True)
    assert(k_palindrome_is_possible('abcdefgfedcba', 1) == True)
    assert(k_palindrome_is_possible('abcdefggfedcba', 1) == True)
    assert(k_palindrome_is_possible('abcdjefggfehdcba', 1) == False)
    assert(k_palindrome_is_possible('azbycxdweuftgsfreqdpcobna', 0) == False)
    assert(k_palindrome_is_possible('azbycxdweuftgsfreqdpcobna', 1) == False)
    assert(k_palindrome_is_possible('azbycxdweuftgsfreqdpcobna', 12) == True)
    assert(k_palindrome_is_possible('azbycxdweuftgsfreqdpcobna', 13) == True)
