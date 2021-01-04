import pprint
import pseudo
import os

#################################################

memory_map = {}
acc_nook = ''
x_nook = ''
nooks = []
vars_type = {}

def hc(t=0):
    return '0' + str(hex(int(t)))[2:]

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
        elif spot[1] == "memory":
            vars_type[spot[2]] = "memory"
            memory_map[spot[2]] = int(spot[3])
        else:
            if spot[2] not in nooks:
                nooks.append(spot[2])
            acc_nook = spot[2]
            vars_type[spot[2]] = "int"
            comm_section.append('LDA\t' + '#$' + hc(spot[3]))

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
            if vars_type[spot[3]] != "a":
                if acc_nook != spot[2]:
                    comm_section.append('LDA\t' + '#$' + hc(spot[3]))
                    acc_nook = spot[2]
            comm_section.append('STA\t' + '$' + hc(memory_map[spot[2]]))

comm_section.append('BRK')

print('')
for c in comm_section:
    print(c)