import os, pprint

par = [
    '#ifndef',
    'print',
    'goto',
    '#ifndef',
    'nook',
    'wantsbells',
    '#endif',
    'heneedsthem',
    '#endif'
]

d = 0
while d < range(len(par)):
    if par[d] == "#ifndef":
        lev = 1
        i = d + 1
        print(str(d) + '\t' + str(par[d]))
        while i < range(len(par)-1) and lev > 0:
            if par[i] == "#ifndef":
                lev += 1
            elif par[i] == "#endif":
                lev -= 1
            print('\t' + str(par[i]) + '\t' + str(lev))
            i += 1
        pprint.pprint(par[d+1:i-1])
    d += 1