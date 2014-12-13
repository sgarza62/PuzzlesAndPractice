# Write a function to check if the value of a binary number (passed in as a
# string) equals the hexadecimal representation of a string.

"""
Implemented my first solution to this problem in C++ (comp_binary_hex.cc), and this is
just a version in Python. For more detail, reference the C++ solution.
"""

def convert_from_base(num, base):
    n = str(num)
    b = int(base)

    value = 0
    for i in range(len(n)-1, -1, -1):
        value += int(n[i], base) * (base**(len(n)-i-1))
    return value
    
def compare_bin_hex(bina, hexa):
    n1 = convert_from_base(bina, 2)
    if not n1:
        raise Exception("Could not convert binary number " +
                        bina + "to base 10.")

    n2 = convert_from_base(hexa, 16)
    if not n1:
        raise Exception("Could not convert hexadecimal number " +
                        hexa + "to base 10.")

    return n1 == n2        
    
if __name__ == '__main__':
    assert(compare_bin_hex(100, 4) == True)
    assert(compare_bin_hex(10100, 14) == True)
    assert(compare_bin_hex(11111, "1F") == True)
    assert(compare_bin_hex(101, 4) == False)
    assert(compare_bin_hex(10100, 15) == False)
    assert(compare_bin_hex(10, 14) == False)
    assert(compare_bin_hex(11111, "AA") == False)

