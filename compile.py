import os, pprint, datetime

"""
0 - hex
1 - dec
2 - ascii
3 - memory
4 - nook

0 - nook
1 - spot
2 - add
3 - visitnotequal
4 - visitequal
"""

asci = ''
data = [
    0, 4, 0, 0, 0, 0, 0,    # a(4) = 0
    1, 4, 1, 0, 0, 0, 0,    # b(1) = 0
    0, 1, 0, 0, 0, 0, 1,    # spot A
    0, 4, 0, 4, 1, 1, 2,    # a = a + 1
    1, 4, 0, 4, 1, 1, 2,
    0, 4, 5, 1, 1, 1, 3     # bne a, 5 goto A
]

tt = 9
t_pos = 0

def new_t():
    t_pos = (t_pos + 1) % tt
    return t_pos

def interpret(s1, s2):
    if s2 == 4:
        return 't' + str(s1)
    else:
        return str(s1)

pre = ''
fin = ''
pos = 0

t = 0
t_max = 2

while pos < len(data):
    x1  = data[pos]
    x2  = data[pos+1]
    y1  = data[pos+2]
    y2  = data[pos+3]
    z1  = data[pos+4]
    z2  = data[pos+5]
    o   = data[pos+6]

    if o == 0:
        if y2 == 0:
            fin += pre + 'la t' + str(x1) + ', ' + str(y1) + ';\n'
        elif y2 == 1:
            fin += pre + 'move t' + str(x1) + ', ' + interpret(y1,y2) + ';\n'
    if o == 1:
        fin += chr(65 + x1) + ':\n'
        pre = '\t'
    if o == 2:
        x = interpret(x1, x2)
        y = interpret(y1, y2)
        fin += pre + 'add ' + x + ', ' + y + ', ' + str(z1) + ';\n'
    if o == 3:
        x = interpret(x1, x2)
        y = interpret(y1, y2)
        fin += pre + 'bne ' + x + ', ' + y + ', ' + chr(65 + x1) + ';'

    pos += 7

print(fin)