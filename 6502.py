import pprint
import pseudo
import os

#################################################

memory_map = {}
acc_nook = ''
x_nook = ''
y_nook = ''
nooks = []
vars_type = {}
spot_count = 0
using = {
    'A': False,
    'X': False,
    'Y': False
}

def hc(t=0):
    return '0' + str(hex(int(t)))[2:]

def ip(val):
    if val == acc_nook:
        using['A'] = True
        return 'A'
    if val == x_nook:
        using['X'] = True
        return 'X'
    if val == y_nook:
        using['Y'] = True
        return 'Y'

def identify(cmd=[],val=[]):
    for u in using.keys(): using[u] = False
    for v in val:
        if len(cmd) >= v:
            ip(cmd[v])

def alloc(val):
    s = [u for u in using.keys() if using[u] == False][0]

#################################################

with open('hshc.hana') as f:
    vars = pseudo.pseudo(f.readlines())

final = []
pprint.pprint(vars)

data_section = []
comm_section = []
for v in range(len(vars)):

    spot = vars[v]
    spots = len(spot)
    mark_var = False

    if spot[0] == "memory":
        comm_section.append('LDA\t' + '#$' + hc(spot[2]))
        comm_section.append('STA\t' + '$' + hc(spot[1]))

    elif spot[0] == "nook":

        if spot[1] == "accumulator":
            vars_type[spot[2]] = "a"
            if len(spot) == 4:
                comm_section.append('LDA\t' + '#$' + hc(spot[3]))
            acc_nook = spot[2]
        elif spot[1] == "memory":
            vars_type[spot[2]] = "memory"
            memory_map[spot[2]] = int(spot[3])
        else:
            if spot[2] not in nooks:
                nooks.append(spot[2])
            x_nook = spot[2]
            vars_type[spot[2]] = "int"
            comm_section.append('LDX\t' + '#$' + hc(spot[3]))

    elif spot[0] == "spot":
        comm_section.append('')
        if len(spot) > 1:
            comm_section.append(spot[1] + ':')
        else:
            comm_section.append("spot" + str(spot_count) + ':')
            spot_count += 1

    elif spot[0] == "hop":
        if len(spot) == 2:
            if spot[1][0] != '(': spot[1] = '(' + spot[1] + ')'
            comm_section.append('JMP\t' + spot[1])
        else:
            identify(cmd=spot, val=[3,4])
            if spot[1] == "!=":
                u = [u for u in using.keys() if using[u]][0]
                comm_section.append('CP' + u + '\t' + '#$' + hc(spot[4]))
                comm_section.append('BNE\t' + spot[2])

    elif spot[0] == "+":
        if vars_type[spot[2]] == "a":
            if spot[3] == "1":
                comm_section.append('INA')
            else:
                if spot[3] in memory_map:
                    comm_section.append('ADC\t' + '$' + hc(memory_map[spot[3]]))
                else:
                    comm_section.append('ADC\t' + '#$' + hc(spot[3]))
        else:
            if x_nook != spot[2]:
                comm_section.append('TAX')
                x_nook = spot[2]
            if spot[3] == "1":
                comm_section.append('INX')
            else:
                if spot[3] in memory_map:
                    comm_section.append('ADC\t' + '$' + hc(memory_map[spot[3]]))
                else:
                    comm_section.append('ADC\t' + '#$' + hc(spot[3]))

    elif spot[0] == "=":
        pre = ''
        t1 = ''
        t2 = ''
        if vars_type[spot[2]] == "a":
            pre = 'STA\t'
            if spot[3] in vars_type:
                if vars_type[spot[3]] == "memory":
                    t1 = '$' + hc(memory_map[spot[3]])
            else:
                t1 = '#$' + hc(int(spot[3]))
            f = (pre + t1 + t2).strip()
            comm_section.append(f)
        elif vars_type[spot[2]] == "memory":
            if vars_type[spot[3]] == "a":
                comm_section.append('STA\t' + '$' + hc(memory_map[spot[2]]))
                pass
            elif vars_type[spot[3]] == "int":
                comm_section.append('STX\t' + '$' + hc(memory_map[spot[2]]))
            else:
                if acc_nook != spot[2]:
                    comm_section.append('LDA\t' + '#$' + hc(spot[3]))
                    acc_nook = spot[2]
                comm_section.append('STA\t' + '$' + hc(memory_map[spot[2]]))

comm_section.append('BRK')

print('')
for c in comm_section:
    print(c)