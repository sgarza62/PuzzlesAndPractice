def min_of_rotated_array(arr):
    '''
    Finds the minimum element of a rotated sorted array

    BREAKING DOWN THE PROBLEM:
    We're going to use a technique called Pattern Matching, where we consider
    similar problems and their existing solutions.

    Okay, so the important information is that it's sorted and rotated.

    If we wanted to find the minimum element in a sorted array, we'd find it at
    index 0, which is obviously O(1) time.
    If we wanted to find some other element in a sorted array, then we would use
    binary search, which is O(log(n)) time.
    If we wanted to find an element in an unsorted array, we would have to
    boringly iterate through the list, which is O(n).

    We could tweak binary search a bit:
    In binary search, we compare the number with a[len/2], and throw away whichever
    half of the array is sure not to contain it.
    Here, we can check if the ascension of the array has "reset"; in other words, we
    can try to find out whether or not the minimum array is in a particular half, by
    checking if a[len/2] is less than a[0]. If it is, then we know the first half of
    that array contains the minimum element, because the ascension has reset
    somewhere.

    Example:
    [3, 4, 5, 6, 7, 8, 0, 1, 2]
    (7 < 3) --> False --> throw away 1st half.

    [7, 8, 0, 1, 2]
    (0 < 7) --> True  --> throw away 2nd half.

    [7, 8, 0]
    (8 < 7) --> False --> throw away 1st half.

    [8, 0]
    return smallest element: 0.

    OOPS!!!
    If we check the first half of the array (as opposed to the second half), we
    face a problem: if the array is fully rotated and thus perfectly sorted (min
    is the zeroeth element in the array), then the first half will be thrown
    away on the first level of the recursion. To avoid this, we should check the
    second half instead of the first.

    CLARIFYING QUESTIONS TO ASK:
    Do we know how large the arrays could get?
    Are we going to have to access elements often enough to warrant indexing?
    Are we worried about space? Or can we make new sliced copies?

    TIME: O(log(n))
    SPACE: O(2n)
    '''
    if len(arr) == 0:
        raise Exception("List arg is empty")
        return None
    elif len(arr) == 1:
        return arr[0]
    elif len(arr) == 2:
        return min(arr)

    if (arr[len(arr)/2] < arr[len(arr)-1]):
        # min is between [0] and [mid] inclusive
        ans = min_of_rotated_array(arr[:1+len(arr)/2])
    else:
        # min is between [mid] and [-1] inclusive
        ans = min_of_rotated_array(arr[len(arr)/2:])
    return ans

# TESTS

# basic test
assert(min_of_rotated_array([3, 4, 5, 6, 7, 1, 2]) == 1)
# when min is at the beginning of the list (ie, sorted)
assert(min_of_rotated_array([1, 2, 3, 4, 5, 6, 7]) == 1)
# when min is at the end of the list
assert(min_of_rotated_array([2, 3, 4, 5, 6, 7, 1]) == 1)
# when array size is 1
assert(min_of_rotated_array([1]) == 1)
# when array size is 2
assert(min_of_rotated_array([2, 1]) == 1)
# when some elements are negative
assert(min_of_rotated_array([-4, -2, 0, 2, 4, 6, 8, -8, -6]) == -8)
# when min is in the middle, also chars
assert(min_of_rotated_array(['d', 'e', 'a', 'b', 'c']) == 'a')
# when list is empty; should throw error
assert(min_of_rotated_array([]) == None)
