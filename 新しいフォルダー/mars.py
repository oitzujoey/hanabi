import pprint
import pseudo
import os

########################################################

reg_count = 7
vars = []
vars_type = {}

addi = "addi\t"
cm = ", "

register_mask = {
    0: "$t0",
    1: "$t1",
    2: "$t2",
    3: "$t3",
    4: "$t4",
    5: "$t5",
    6: "$t6",
    7: "$t7",   
}

presence = {}
registers = [None for r in range(reg_count)]
memory = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
cursor = 0
memory_map = {}

var_start = {}
var_end = {}

def garbage_collection(var):
    memory[memory_map[var]] = None
    del memory_map[var]
    registers[find_register(var)] = None

def relevant(var, loc=0):
    global vars
    global reg_count

    start = var_end[var]
    end = start + reg_count
    if end > len(vars): end = len(vars)
    if loc >= start and loc <= end:
        return True
    else:
        return False

def memory_store(var):
    global cursor
    global memory_map
    global memory

    if var not in memory_map:
        memory_map[var] = cursor
        memory[cursor] = var
        cursor += 1
    registers[find_register(var)] = None

def find_register(var):
    global registers

    for spot in range(len(registers)):
        if registers[spot] == var:
            return spot
    return None

def swap_out(var,loc):
    global registers
    global memory_store

    if var in registers:
        return True

    free_reg = []
    for spot in range(len(registers)):
        r = registers[spot]
        if r == None:
            registers[spot] = var
            return True
        else:
            if not relevant(r,loc): free_reg.append(r)

    sel = 0 if len(free_reg) == 0 else find_register(free_reg[0])
    memory_store(registers[sel])
    registers[sel] = var
    return False

def twos(val_str, bytes):
    import sys
    val = int(val_str, 2)
    b = val.to_bytes(bytes, byteorder=sys.byteorder, signed=False)                                                          
    return int.from_bytes(b, byteorder=sys.byteorder, signed=True)

########################################################

with open('hshc.hana') as f:
    vars = pseudo.pseudo(f.readlines())

final = []
pprint.pprint(vars)

def ret(t):
    return register_mask[find_register(spot[t])]

tt = {}
for i in range(10):
    tt[i] = ''

data_section = []
comm_section = []
for v in range(len(vars)):
    spot = vars[v]
    spots = len(spot)
    mark_var = False

    if spots > 1:
        tt[1] = find_register(spot[1])
        if spots > 2:
            tt[2] = find_register(spot[2])
            if spots > 3:
                tt[3] = find_register(spot[3])
                if spots > 4:
                    tt[4] = find_register(spot[4])

    if spot[0] == "nook":
        if spot[1] == "string":
            data_section.append(spot[2] + ':\t.asciiz ' + spot[3])
            vars_type[spot[2]] = 'string'

        else:
            if spot[2] not in var_start:
                vars_type[spot[2]] = spot[1]
                var_start[spot[2]] = v
                var_end[spot[2]] = v
            else:
                var_end[spot[2]] = v

            swap_out(spot[2],loc=v)

            if len(spot) == 4:
                comm_section.append(addi + ret(2) + ", $zero, " + spot[3])
            else:
                comm_section.append("and\t" + ret(2) + cm + ret(2) + ", $zero")

    elif spot[0] == "spot":
        comm_section.append("\n" + spot[1] + ":")

    elif spot[0] == "back":
        comm_section.append("j\t" + spot[1])

    elif spot[0] == "hop":
        if spot[1] == ">":
            comm_section.append("bgt\t" + ret(3) + cm + ret(4) + cm + spot[2])
        elif spot[1] == "<":
            comm_section.append("blt\t" + ret(3) + cm + ret(4) + cm + spot[2])
        elif spot[1] == ">=":
            comm_section.append("bge\t" + ret(3) + cm + ret(4) + cm + spot[2])
        elif spot[1] == "<=":
            comm_section.append("ble\t" + ret(3) + cm + ret(4) + cm + spot[2])
        elif spot[1] == "!=":
            comm_section.append("bne\t" + ret(3) + cm + ret(4) + cm + spot[2])
        else:
            comm_section.append("beq\t" + ret(3) + cm + ret(4) + cm + spot[2])

    elif spot[0] == "say":
        vt = vars_type[spot[1]]
        print(vt)
        if vt == "string":
            comm_section.append('li\t$v0' + cm + '4')
            comm_section.append('la\t$a0' + cm + spot[1])
            comm_section.append('systemcall')
            comm_section.append('')
        elif vt == "int":
            comm_section.append('li\t$v0' + cm + '1')
            comm_section.append('add\t$a0' + cm + ret(1) + cm + "$zero")
            comm_section.append('systemcall')
            comm_section.append('')

    elif spot[0] == "+":
        if tt[1] != None and tt[2] != None and tt[3] != None:
            comm_section.append("add\t" + ret(1)+ cm + ret(2) + cm + register_mask[find_register(spot[3])])
        elif tt[3] == None:
            comm_section.append(addi + ret(1) + cm + ret(2) + cm + spot[3])

    elif spot[0] == "-":
        if tt[1] != None and tt[2] != None and tt[3] != None:
            comm_section.append("sub\t" + ret(1)+ cm + ret(2) + cm + register_mask[find_register(spot[3])])
        elif tt[3] == None:
            comm_section.append(addi + ret(1) + cm + ret(2) + ", -" + spot[3])

    elif spot[0] == "=":
        if tt[3] == None:
            comm_section.append(addi + ret(1) + ", $zero, " + spot[3])
        else:
            comm_section.append("add\t" + ret(2) + cm + ret(3) + ", $zero")

pprint.pprint(vars_type)

if len(data_section) > 0:
    print('.data')
    for c in data_section:
        print(c)
    print('')
print('.text')
for c in comm_section:
    print(c)

"""
pprint.pprint(var_start)
pprint.pprint(var_end)
for v in var_start.keys():
    print(v + '\t' + str(relevant(v,loc=len(vars))))

print('\n')

pprint.pprint(registers)
"""