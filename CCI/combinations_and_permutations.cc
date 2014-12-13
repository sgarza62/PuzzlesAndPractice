#include <math.h>

int factorial(int n) {
  if (n == 1) return 1;
  else return n * factorial(n-1);
}

// PERMUTATIONS: ORDERED POSSIBILITIES

int permutationsNoRepeats(int n, int r) {
  /*
    We have n things to choose from. We must choose r things.
    Since repeats are NOT allowed, there's 1 less item to choose from for each r.

    We have n things to choose from for the first slot.
    We have n-1 things to choose from for the second slot.
    We have n-2 things to choose from for the third slot.
    We have n-(r-1) things to choose from for rth slot.

    (n) * (n-1) * (n-2) * ... * (n-r)

    Where n=10 and r=4:
    (10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 ) / (6 * 5 * 4 * 3 * 2 * 1)
    = (10 * 9 * 8 * 7)

    n! / (n-r)!
  */
  return factorial(n) / factorial(n-r);
}

int permutationsWithRepeats(int n, int r) {
  /*
    We have n things to choose from. We must choose r things.
    Since repeats are allowed, we have n things to choose from for each r.
    If r is 1, there are n options.
    If r is 2, then for each of the original n options, there are n options.
    n * n * n * ... (r times)
    amount of possibilities is n^r.
  */
  return pow(n, r);
}


// COMBINATIONS: UNORDERED POSSIBILITIES

int combinationsNoRepeats(int n, int r) {
  /*
    We have n things to choose from. We must choose r things, and we don't care
    about the order; so (1, 2, 3) is the same as (3, 2, 1).

    For some set of size s, there are s permutations (assuming s slots; ie all).
    EXAMPLE: {(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)}.
    We know this from above formula:
    n! / (n-r)!
    And where r = n:
    n! / 1 = n!

    In the set of permutations above, there is only one combination.
    Again, in a set of 4, there are 4! permutations and only 1 combination.

    If n=4, and we only want to fill two slots (ie, r=2):
    r=1, {{1}, {2}, {3}, {4}}                               |4|
    r=2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}   |6|
    r=3, {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}}       |4|
    r=4, {{1, 2, 3, 4}}                                     |1|

    So, it appears that we must find the permutation (no repeat) count, then
    reduce it so that for all possible permutations of r-sized subsets, we only
    count 1.

    For example we cross out the 2!, where r=2:
    ((4 * 3 * 2!) / (4-2)!) * (1 / 2!)

    So,
    n! / (n-r)!(r!)
  */
  return factorial(n) / (factorial(n-r) * factorial(r));
}

int combinationsWithRepeats(int n, int r) {
  /*
    We have n things to choose from. We must choose r things, and we don't care
    about the order; so (1, 3, 3) is the same as (3, 3, 1).
    
    We allow repeats, so where n=3 and r=2:
    {{1, 2}, {1, 3}, {2, 3}, {1, 1}, {2, 2}, {3, 3}}        |6|

    We can represent the selections differently from set notation:
    x|x|, x||x, |x|x, xx||, |xx|, ||xx
    Here, the symbol "|" acts as a delimeter between values of a certain type.
    
    Each multiset contains r x's, and n-1 delimeters. So

    So, if we have r "x's" and n-1 "|'s", we have a total of (r + n - 1) slots.
    If we think of each slot as an independent value: ie, as 123456, and we have
    to choose r of them (for the x's), then we have have a simple no-repeat
    permutation problem, where there are (r + n - 1) choices:
    (r + n - 1)! / ((r + n - 1) - r)!(r!)
    which simplifies to:
    (r + n - 1)! / (n - 1)!(r!)
  */
  return factorial(r+n-1) / (factorial(n-1) * factorial(r));
}


int main() {return 0;}
