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

def validString(string):
    valid = True;
    myLen = len(string);
    if(myLen == 1):
        return True;
    elif(myLen == 2):
        return string[0] <= string[1]
    else:
        for i in range(1, myLen):
            if string[i] < string[i-1]:
                valid = False
                break;
        if(valid):
            return True;
        else:
            start = string[0:i]
            end = string[i:]
           # print(start)
        #    print(end)
            if(validString(start) and validString(end)):
                if len(start) <= len(end):
                    for i in range(0, len(start)):
                       if(start[i] < end[i]):
                            return True;
                       elif(start[i] > end[i]):
                           return False;
                    return True;
                elif (len(start) >= len(end)):
                    for j in range(0, len(end)):
                        if(start[j] < end[j]):
                            return True;
                        elif(start[j] > end[j]):
                            return False;
                    return False;
            else:
                return validString(end);
    return False;
# numpy and scipy are available for use
import numpy
import scipy

numberOfStrings = get_number();
for i in range(0, numberOfStrings):
    string = get_word();
    if(validString(string)):
        print(1, end = '');
    else:
        print(0, end = '');