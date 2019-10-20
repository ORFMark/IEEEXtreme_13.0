#import time
buffer = "" # output string buffer
num_outputs = 0 # number of outputs
# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

def move_rook(direction, location):
    # record the movement of a rook into a string buffer and increments the
    # number of moves that have been made
    global buffer
    global num_outputs
    # direction is a single character: 'L', 'R', 'U', 'D', 'T', 'P'
    # location is a dictionary {'x':int, 'y':int}
    buffer += "{0} {1} {2}\n".format(direction['x'], direction['y'], location)
    num_outputs += 1

def value_in_rooks(rooks, dict_param, value):
    # checks if value is in rooks, and if found return the idx of the rook that
    # contains value in its specified dictionary entry
    # if not found, return -1
    # note: this function is designed for checking if a column or row of a rook
    # matches where another rook wants to move to
    for idx in range(0, len(rooks)):
        if rooks[idx][dict_param] == value:
            return idx
    return -1

def graphical_display(rooks, targets):
    # displays a graphical representation of the rooks
    n = 20; # maximum display size
    board = [ [ '.' for i in range(n) ] for j in range(n) ];
    for i in range(0,len(rooks)):
        # set board at targets(x,y) to a '.'
        board[targets[i]['x']][targets[i]['y']] = 'X'
        # set board at rooks(x,y) to a 'R'
        board[rooks[i]['x']][rooks[i]['y']] = 'R'
        # do rooks second so they overwrite the first
    # print the results
    for i in range(0,len(board)):
        print(board[i][:])
    print("\n")
    time.sleep(1)

n = get_number() # number of elements
rooks = [] # array of rooks
targets = [] # array of targets
for __ in range(0,n):
    rooks.append({'x': get_number(), 'y': get_number()}) # get input to list of dicts
for __ in range(0,n):
    targets.append({'x': get_number(), 'y': get_number()}) # get input to list of dicts

# sort the rooks by column 'x'
rooks = sorted(rooks, key = lambda i: i['x'])
# sort the targets by column 'x'
targets = sorted(targets, key = lambda i: i['x'])

# begin prepatory column (x) algorithm
# create list of deltaX's, starting from the left
# no target may be used twice
deltaX = [] # array of difference in X between targets and rooks
for column_iterator in range(0,n):
    deltaX.append(targets[column_iterator]['x']-rooks[column_iterator]['x'])

# algorithm to move rooks to their target column
# loop through all rooks twice (worst case scenario)
# attempt to move edge left-most rook towards target. If another rook is in the
# way, skip it and move to the next rook. Eventually, a rook can move. Worst-
# case, this will be the last rook, which will land at its target square if all
# prior rooks could not move.
for safety_iterator in range(0,n):
    for column_iterator in range(0,n):
        # move all values towards their target if possible
        if deltaX[column_iterator] == 0:
            continue # do not do anything if no moving needs to be done
        # determine the sign of the direction to move
        sign = deltaX[column_iterator] / abs(deltaX[column_iterator])
        # move until another rook is hit with the same column
        while (value_in_rooks(rooks, 'x', rooks[column_iterator]['x'] + sign) == -1 and deltaX[column_iterator] != 0):
            if sign > 0:
                move_rook(rooks[column_iterator], 'R')
            else:
                move_rook(rooks[column_iterator], 'L')

            #graphical_display(rooks,targets) #TODO comment
            rooks[column_iterator]['x'] += sign # move
            deltaX[column_iterator] -= sign # decrease distance to go

# find the deltaY's
deltaY = [] # array of different in Y between rooks and targets
# note that rooks and targets should all share corresponding x's
for row_iterator in range(0,n):
    deltaY.append(rooks[row_iterator]['y']-targets[row_iterator]['y'])

# figure out the order of y's of the targets based on indicies
# the first is the lowest value
yTargetOrder = []
for i in range(0,n):
    yTargetOrder.append(targets[i]['y']) # pull all y-values
temp = yTargetOrder[:] # copy y-values into a temp array
yTargetOrder.sort() # sort the target values, low to high
# swap each value in yTargetOrder with the index associated with each sorted
# value.
for i in range(0,n):
    yTargetOrder[i] = temp.index(yTargetOrder[i])
yTargetMin = targets[yTargetOrder[0]]['y']; # minimum target

# figure out the order of y's of the rooks based on indicies
# the first is the highest value
yRookOrder = []
for i in range(0,n):
    yRookOrder.append(rooks[i]['y'])
temp = yRookOrder[:]
# sort the values, high to low
yRookOrder.sort()
yRookOrder.reverse()
for i in range(0,n):
    yRookOrder[i] = temp.index(yRookOrder[i])
yRookMaxY = rooks[yRookOrder[0]]['y'] # high to low implies this is the max val

# note that the yRookMaxY value needs to be raised to at least the maximum value
# of the targets.
if targets[yTargetOrder[-1]]['y'] > yRookMaxY:
    yRookMaxY = targets[yTargetOrder[-1]]['y'];

for row_iterator in range(0,n):
    # the rooks need to move such that their order is that of the targets
    # take each rook, starting with the one in the highest location, and move it up until
    # it reaches the highest location rook + 2 * relative order
    # if a rook needs to pass another rook, move the other rook off the board,
    # move the lower rook two past, and then move the other rook back on the board
    while (rooks[yRookOrder[row_iterator]]['y'] < (yRookMaxY) + 2 * targets[yRookOrder[row_iterator]]['y']):
        # the previous line compares on the left and right respectively:
        # - the y value of the rook at the row_iterator-th value in yRookOrder
        # - the maximum rook value before movement plus 2 times the index of the
        #   index of yTargetOrder for this rook's index
        inRooksIdx = value_in_rooks(rooks, 'y', rooks[yRookOrder[row_iterator]]['y'] + 1)
        if inRooksIdx == -1: # there is no conflict moving the rook up
            #graphical_display(rooks,targets) # TODO comment
            move_rook(rooks[yRookOrder[row_iterator]], 'U')
            rooks[yRookOrder[row_iterator]]['y'] += 1
            deltaY[yRookOrder[row_iterator]] += 1
        else:
            # remove the rook that is conflicting with our rook
            move_rook(rooks[inRooksIdx], 'T')
            #graphical_display(rooks,targets) #TODO comment
            # move up two to pass the first rook
            move_rook(rooks[yRookOrder[row_iterator]], 'U')
            rooks[yRookOrder[row_iterator]]['y'] += 1
            deltaY[yRookOrder[row_iterator]] += 1
            move_rook(rooks[yRookOrder[row_iterator]], 'U')
            rooks[yRookOrder[row_iterator]]['y'] += 1
            deltaY[yRookOrder[row_iterator]] += 1
            #graphical_display(rooks,targets) # TODO comment
            # replace the original rook
            move_rook(rooks[inRooksIdx], 'P')

# now move down rooks until deltaY = zero for each, starting with the rook with
# the smallest y-value (lowest position)
# this order will be yRookOrder, but sorted low to high
invYRookOrder = []
for i in range(0,n):
    invYRookOrder.append(rooks[i]['y'])
temp = invYRookOrder[:]
# sort low to high
invYRookOrder.sort()
for i in range(0,n):
    invYRookOrder[i] = temp.index(invYRookOrder[i])

for row_iterator in range(0,n):
    # move down until deltaY is zero
    while (deltaY[invYRookOrder[row_iterator]] != 0):
        #graphical_display(rooks,targets) #TODO comment
        move_rook(rooks[invYRookOrder[row_iterator]], 'D')
        rooks[invYRookOrder[row_iterator]]['y'] -= 1
        deltaY[invYRookOrder[row_iterator]] -= 1

# output results to the screen
print(num_outputs)
print(buffer)