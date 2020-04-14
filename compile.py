import os, pprint

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
"""

asci = ''
data = [int(t) for t in "0 4 0 0 0 0 0 0 1 0 0 0 0 1 0 4 0 4 1 1 2 0 4 5 1 1 1 3".split(' ')]

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
        if y1 == 0 and y2 == 0:
            fin += pre + 'la t' + str(t) + ', 0;\n'
    if o == 1:
        fin += chr(65 + x1) + ':\n'
        pre = '\t'
    if o == 2:
        fin += pre + 'add t' + str(x1) + ', t' + str(y1) + ', ' + str(z1) + ';\n'
    if o == 3:
        fin += pre + 'bne t' + str(x1) + ', ' + str(y1) + ', ' + chr(65 + x1) + ';'

    pos += 7

print(fin)