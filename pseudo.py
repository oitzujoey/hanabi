import pprint

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
    'say',
    'friend',
    'memory']

nooks = []
nook_count = 0
spot_count = 0

def valuify(value):
    if value.isnumeric():
        return int(value)
    else:
        return value

def split_complex(base_cmd,header=None):
    global nook_count
    global spot_count
    global dataset
    global nooks

    if base_cmd[0] not in command:
        base_cmd = ["="] + base_cmd
    
    if base_cmd[0] in command:
        if header != None:
            for b in range(len(base_cmd)):
                if base_cmd[b] in nooks:
                    base_cmd[b] = header + '_' + base_cmd[b]

        if len(base_cmd) > 1:
            if base_cmd[0] == "nook":
                if len(base_cmd) == 2:
                    base_cmd.append('0')
                if base_cmd[1] not in ['string', 'memory', 'accumulator', 'int', 'float', 'double','char','unsignedchar','signedchar','unsignedint','short','unsignedshort','long','unsignedlong']:
                    if base_cmd[2][0] == "\"":
                        base_cmd.insert(1,"string")
                    else:
                        base_cmd.insert(1,"int")
                if base_cmd[2] in nooks: dataset.append(['trash',base_cmd[2]])
                nooks.append(base_cmd[2])
                if header != None:
                    base_cmd[2] = header + '_' + base_cmd[2]

            elif base_cmd[0] == "friend":
                with open(base_cmd[1],'r') as f:
                    d = pseudo(f.readlines(),header=base_cmd[1][:base_cmd[1].find('.')])
                    pprint.pprint(d)
                    dataset.append(d)
                return None

            elif base_cmd[0] == "hop":
                if base_cmd[1] not in ['=','<','>','<=','>=','!=']:
                    base_cmd.insert(1,'=')
            
            elif base_cmd[0] == "memory":
                pass

            else:
                if base_cmd[1] not in nooks and base_cmd[1].isnumeric():
                    dataset.append(["nook", "int", "t" + str(nook_count)])
                    base_cmd.insert(1,"t"+str(nook_count))
                    nooks.append("t"+str(nook_count))
                    nook_count += 1
                elif len(base_cmd) == 3:
                    base_cmd.insert(1,base_cmd[1])
                
        else:
            if base_cmd[0] == "spot":
                base_cmd.append("spot"+str(spot_count))
                spot_count += 1
            
            elif base_cmd[0] == "back":
                for t in reversed(range(spot_count)):
                    if ['back','spot'+str(t)] not in dataset:
                        base_cmd.append('spot'+str(t))
                        break                

    return base_cmd

def layer(depth,layers=0,header=None):
    global dataset

    spa = ''.join(['\t' for t in range(layers)])

    paren_layer = 0
    internal_layers = layers

    d = 0
    in_quotes = -1
    length = len(depth)
    base_cmd = []

    if length > 0:
        #print("\n\n")
        while d < length:
            char = depth[d]

            if char == "\"":
                in_quotes = in_quotes * -1
                if in_quotes == -1:
                    base_cmd.append(depth[:d+1])
                    depth = depth[d+1:]
                    d = -1

            if in_quotes == -1:

                if char == " " and paren_layer == 0:
                    base_cmd.append(depth[:d])
                    depth = depth[d+1:]
                    #print(spa + "Depth: $" + depth + "$")
                    d = -1

                if char == "(":
                    paren_layer += 1

                elif char == ")":
                    paren_layer -= 1
                    if paren_layer == 0:
                        internal_layers += 1
                        #print(spa + "Running: $" + str(depth[2:d]) + "$")
                        layer(depth=depth[2:d],layers=internal_layers)
                        depth = dataset[-1][1] + depth[d+1:]
                        d = -1

            #print(spa + char + '$\t\t' + str(in_quotes))

            d += 1
            length = len(depth)

        if len(depth) > 0:
            base_cmd.append(depth)
        base_cmd = split_complex(base_cmd,header=header)
        #print(spa + str(base_cmd))
        if base_cmd is not None:
            dataset.append(base_cmd)

def pseudo(code,header=None):
    global dataset

    for c in code:
        if ';' in c:
            c = c[:c.find(';')]
        c = c.strip()
        if c != "":
            layer(depth=c,header=header)
    
    return dataset