from operator import attrgetter
from random import randint

back_red =     '\x1b[101m'
back_darkred = '\x1b[41m'
back_blue =    '\x1b[46m'
back_darkblue ='\x1b[104m'
front_black =  '\x1b[30m'
reset =        '\x1b[0m'

class Point():
    def __init__(self, x, y, dist = -1):
        self.x, self.y, self.dist = x, y, dist

    def __repr__(self):
        return ("(" + str(self.x) + ", " + str(self.y) + ") "
                "[" + str(self.dist) + "]")

def distance(a, b):
    """ Manhattan distance """
    return abs(a.x - b.x) + abs(a.y - b.y)

def collective_distance(a, b, c, m):
    """ Sum of the distances of all three vertices to point m """
    return distance(a, m) + distance(b, m) + distance(c, m)

def get_meeting_point_fast(a, b, c):
    '''
    Function returns ideal meeting point in constant time using Harrison's
    algorithm, where meeting point is least collective walking distance
    possible.
    '''
    #check vertex
    vertex_a = collective_distance(a, b, c, a)
    vertex_b = collective_distance(a, b, c, b)
    vertex_c = collective_distance(a, b, c, c)

    #check right trangle points
    ab1 = Point(b.x, a.y)
    right_ab1 = collective_distance(a, b, c, ab1)

    ab2 = Point(a.x, b.y)
    right_ab2 = collective_distance(a, b, c, ab2)

    bc1 = Point(c.x, b.y)
    right_bc1 = collective_distance(a, b, c, bc1)

    bc2 = Point(b.x, c.y)
    right_bc2 = collective_distance(a, b, c, bc2)

    ca1 = Point(a.x, c.y)
    right_ca1 = collective_distance(a, b, c, ca1)

    ca2 = Point(c.x, a.y)
    right_ca2 = collective_distance(a, b, c, ca2)

    #find smallest value
    shortest_dist = min(vertex_a, vertex_b, vertex_c,
                        right_ab1, right_ab2,
                        right_bc1, right_bc2,
                        right_ca1, right_ca2)

    distances_and_points = [(vertex_a, a), (vertex_b, b), (vertex_c, c),
                            (right_ab1, ab1), (right_ab2, ab2),
                            (right_bc1, bc1), (right_bc2, bc2),
                            (right_ca1, ca1), (right_ca2, ca2)]


    print [x[1] for x in distances_and_points if x[0] == shortest_dist]
    meeting_point = [x[1] for x in distances_and_points if x[0] == shortest_dist][0]

    return meeting_point


def get_meeting_point(a, b, c, ince):
    """ Logarithmic check for best meeting point """
    # use incenter as first guess
    best = ince
    while True:
        left = Point(best.x - 1, best.y)
        left.dist = collective_distance(a, b, c, left)

        top = Point(best.x, best.y - 1)
        top.dist = collective_distance(a, b, c, top)

        right = Point(best.x + 1, best.y)
        right.dist = collective_distance(a, b, c, right)

        bottom = Point(best.x, best.y + 1)
        bottom.dist = collective_distance(a, b, c, bottom)

        best_neighbor = min(left, top, right, bottom, key=attrgetter('dist'))
        if best.dist <= best_neighbor.dist:
            print best
            return best
        else:
            best = best_neighbor

def compare():
    a = Point(12, 28)
    b = Point(3, 18)
    c = Point(20, 29)

    ince = incenter(a, b, c)

    print get_meeting_point(a, b, c, ince) == get_meeting_point_fast(a, b, c)
    

def number_grid(a, b, c, meeting_point, grid_size):
    arr = [0] * grid_size**2
    for i in range(grid_size):
        for j in range(grid_size):
            p = Point(i, j)
            diff = collective_distance(a, b, c, p) - meeting_point.dist
            arr[grid_size*i+j] = diff
    return arr


def incenter(a, b, c):
    """ Returns the center of the incircle of a triangle. """
    ab, bc, ca = distance(a, b), distance(b, c), distance(c, a)
    x = (bc * a.x + ca * b.x + ab * c.x) / (ab + bc + ca)
    y = (bc * a.y + ca * b.y + ab * c.y) / (ab + bc + ca)

    ince = Point(int(round(x)), int(round(y)))
    ince.dist = collective_distance(a, b, c, ince)
    return ince


def centroid(a, b, c):
    """ Returns intersection of three medians. """ 
    x = (a.x + b.x + c.x)/ 3.0
    y = (a.y + b.y + c.y) / 3.0

    cent = Point(int(round(x)), int(round(y)))
    cent.dist = collective_distance(a, b, c, cent)
    return cent


def plot_graph(a, b, c, grid_size):
    ince = incenter(a, b, c)
    cent = centroid(a, b, c)
    meet_point = get_meeting_point(a, b, c, ince)
    extra_step_array = number_grid(a, b, c, meet_point, grid_size)

    lines = [list("_" + ("|_" * grid_size) + "\n")] * grid_size

    def alter_point(line_index, char_index, char="", color=""):
        line_copy = lines[line_index][:]
        if char: line_copy[char_index] = line_copy[char_index].replace('_', char)
        line_copy[char_index] = color + line_copy[char_index] + reset
        lines[line_index] = line_copy

    # plot the three users on the grid
    for p in [a, b, c]:
        if ([(a.x, a.y), (b.x, b.y), (c.x, c.y)].count((p.x, p.y)) == 1):
            alter_point(p.y, p.x*2, color=back_red)
        else:
            alter_point(p.y, p.x*2, color=back_darkred)

    # plot the best meeting point on the grid, and the runner-ups
    for i in range(len(extra_step_array)):
        extra = extra_step_array[i]
        if extra < 10:
            line_number = (i % grid_size)
            char_number = (i / grid_size) * 2
            if extra != 0:
                alter_point(line_number, char_number, char=str(extra))
            else:
                alter_point(line_number, char_number,
                            char="0", color=front_black)

    # plot the incenter
    if (ince.dist == 0):
        alter_point(ince.y, ince.x*2, color=back_darkblue, char="#")
    else:
        alter_point(ince.y, ince.x*2, color=back_darkblue)

    # plot the centroid
    if (cent.dist == 0):
        alter_point(cent.y, cent.x*2, color=back_blue, char="#")
    else:
        alter_point(cent.y, cent.x*2, color=back_blue)

    # construct grid
    for i in range(len(lines)): lines[i] = "".join(lines[i])
    grid = ""
    for line in lines: grid += line
    grid += " " + ("| " * grid_size)
    print grid
    

if __name__ == "__main__":
    import os
    os.system('cls' if os.name == 'nt' else 'clear')

    while True:
        a = raw_input(
            "Type six digits between 0 and 29 to form 3 coordinates, like:" +
            "\n8 13 4 29 0 24" +
            "\nor simply press ENTER for random coordinates" + 
            "\n>>> ")
        print "-" * 60 + "\n"

        # Decide the 3 coords
        a = a.split(" ")
        if len(a) == 6:
            a = [int(x) for x in a]
            for i in a:
                assert(i >= 0 and i <= 29)
            p1 = Point(a[0], a[1])
            p2 = Point(a[2], a[3])
            p3 = Point(a[4], a[5])
        else:
            p1 = Point(randint(0, 29), randint(0, 29))
            p2 = Point(randint(0, 29), randint(0, 29))
            p3 = Point(randint(0, 29), randint(0, 29))


        # Print out info
        print ("People at: " +
               "(" + str(p1.x) + ", " + str(p1.y) + ") " +
               "(" + str(p2.x) + ", " + str(p2.y) + ") " +
               "(" + str(p3.x) + ", " + str(p3.y) + ") \n\n")


        m = get_meeting_point(p1, p2, p3, incenter(p1, p2, p3))
        print "Meeting Point at: (" + str(m.x) + ", " + str(m.y) + ")"
        print "Total distance traveled: " + str(m.dist) + "\n"
        plot_graph(p1, p2, p3, 30)
    
        print ("\n  " + back_red + " " + reset + " = PERSON            " +
               back_blue + " " + reset + " = CENTROID           " +
               back_darkblue + " " + reset + " = INCENTER           \n")
               
        raw_input("")
        os.system('cls' if os.name == 'nt' else 'clear')
