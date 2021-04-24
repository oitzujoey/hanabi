import pprint

reg_count = 2

vars = [
    ["x1"],
    ["x1", "3"],
    ["x2"],
    ["x3"],
    ["x1","5"],
    ["x6"],
    ["x1","9"]
]

presence = {}
registers = [None for r in range(reg_count)]
memory = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
cursor = 0
memory_map = {}

var_start = {}
var_end = {}

def predict(var,loc):
    global vars
    global reg_count

    upper = loc + reg_count
    if upper > len(vars): upper = len(vars)

    for s in range(loc,upper):
        if vars[s][0] == var:
            return True
    return False

def relevant(var, loc=len(vars)):
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

for v in range(len(vars)):
    spot = vars[v]
    presence[v] = []

    if spot[0] not in var_start:
        var_start[spot[0]] = v
        var_end[spot[0]] = v
        presence[v].append(spot[0])
    else:
        presence[v].append(spot[0])
        var_end[spot[0]] = v

    swap_out(spot[0],loc=v)

pprint.pprint(var_start)
pprint.pprint(var_end)
for v in var_start.keys():
    print(v + '\t' + str(relevant(v)))

print('\n')

pprint.pprint(registers)