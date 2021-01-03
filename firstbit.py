import pprint

code = """

nook x 1
spot
    + x 1
    hopsame outspot x 10
back
spot outspot

"""

def valuify(value):
    if value.isnumeric():
        return int(value)
    else:
        return value

# NOOK      determines memory location
# SPOT      determines loop back point
# MEMORY    determines where in memory a thing is
# HOPSAME   if the same, go to location
# HOPMORE   if more, go to location
# HOPLESS   if less, go to location
# SETSAME   if the same, set context
# SETMORE   if more, set context
# SETLESS   if less, set context

dataset = []
command = [
    '+',
    '-',
    '=',
    '*',
    '%',
    '/',
    'nook',
    'spot',
    'back',
    'pocket',
    'hop',
    'hopsame']

nooks = []
nook_count = 0

def split_complex(base_cmd):
    global nook_count

    if base_cmd[0] not in command:
        base_cmd = ["="] + base_cmd
    
    if base_cmd[0] in command:
        if len(base_cmd) > 1:
            if base_cmd[0] == "nook":
                nooks.append(base_cmd[1])

            if base_cmd[1] not in nooks and base_cmd[1].isnumeric():
                dataset.append(["nook", "t" + str(nook_count)])
                base_cmd.insert(1,"t"+str(nook_count))
                nooks.append("t"+str(nook_count))
                nook_count += 1

    return base_cmd

def layer(depth,layers=0):
    global dataset

    spa = ''.join(['\t' for t in range(layers)])

    paren_layer = 0
    internal_layers = layers

    d = 0
    length = len(depth)
    base_cmd = []
    while d < length:
        char = depth[d]
        #print(spa + char + '\t\t' + str(paren_layer))
        
        if char == " " and paren_layer == 0:
            base_cmd.append(depth[:d])
            depth = depth[d+1:]
            #print(spa + "Depth: $" + depth + "$")
            d = 0

        if char == "(":

            paren_layer += 1

        elif char == ")":
            paren_layer -= 1
            if paren_layer == 0:
                internal_layers += 1
                #print(spa + "Running: $" + str(depth[2:d]) + "$")
                layer(depth=depth[2:d],layers=internal_layers)
                depth = dataset[-1][1] + depth[d+1:]
                d = 0

        d += 1
        length = len(depth)
    base_cmd.append(depth)

    base_cmd = split_complex(base_cmd)
    #print(spa + str(base_cmd))
    dataset.append(base_cmd)

for c in code.split('\n'):
    c = c.strip()
    if c != "":
        layer(depth=c)

#print('\n\n')
pprint.pprint(dataset)