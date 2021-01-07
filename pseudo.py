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
    'memory',
    'trash']

datatypes = [
    'string',
    'memory',
    'accumulator',
    'int',
    'float',
    'double',
    'char',
    'unsignedchar',
    'signedchar',
    'unsignedint',
    'short',
    'unsignedshort',
    'long',
    'unsignedlong',
    'register'
    ]

operators = ['=','<','>','<=','>=','!=']

nooks = []
spots = []
nook_count = 0
spot_count = 0

def valuify(value):
    if value.isnumeric():
        return int(value)
    else:
        return value

class directive:

    def __init__(self, command=None, modifier=None, location=None, input=None, results=None):
        self.command = command
        self.modifier = modifier
        self.location = location
        self.input = input
        self.results = results
        
    def output(self):
        print('Command:\t' + str(self.command))
        print('Modifier:\t' + str(self.modifier))
        print('Location:\t' + str(self.location))
        print('Input:\t\t' + str(self.input))
        print('Results:\t' + str(self.results))
        print()

def new_spot(loc=len(dataset)):
    # Create new spot at beginning of code
    spots.append('spot' + str(len(spots)))
    dataset.insert(loc,directive(
        command=command.index('spot'),
        location=spots[-1]
    ))

def nook_func(base_cmd=[],header=None):
    bc = len(base_cmd)
    direct = directive()
    start = bc - 2

    # Prepare base datatype
    if base_cmd[1] in datatypes:
        direct.modifier = datatypes.index(base_cmd[1])
    else:
        start -= 1
        if base_cmd[1] == "\"":
            direct.modifier = datatypes.index('string')
        else:
            direct.modifier = datatypes.index('int')

            # Automatic garbage collection
            if base_cmd[start] in nooks:
                dataset.append(directive(
                    command=command.index('trash'),
                    input=base_cmd[start]))
            
    if header != None:
        base_cmd[2] = header + '_' + base_cmd[2]

    if start == 0:
        direct.results = 't' + str(len(nooks))
    else:
        if start > 0: direct.results = base_cmd[start+1]
        if start > 1: direct.input = base_cmd[start]

    nooks.append(base_cmd[start])
    return direct

def hop_func(base_cmd=[]):
    bc = len(base_cmd)
    direct = directive()
    start = 3

    # Apply operator if does not exist
    if base_cmd[1] in operators:
        direct.modifier = operators.index(base_cmd[1])
    else:
        direct.modifier = operators.index('=')
        start -= 1

    # If there is no spot specified
    if base_cmd[start - 1] in spots:
        direct.location = base_cmd[start - 1]
    else:
        if len(spots) == 0:
            new_spot(0)
        start -= 1
        direct.location = spots[-1]

    if bc - start > 0: direct.input = base_cmd[start]
    if bc - start > 1: direct.results = base_cmd[start+1]
    return direct

def split_complex(base_cmd,header=None):
    global nook_count
    global spot_count
    global dataset
    global nooks

    bc = len(base_cmd)
    direct = directive()

    if base_cmd[0] not in command:
        base_cmd = ["="] + base_cmd
    
    if base_cmd[0] in command:
        direct.command = command.index(base_cmd[0])

        if header != None:
            for b in range(len(base_cmd)):
                if base_cmd[b] in nooks:
                    base_cmd[b] = header + '_' + base_cmd[b]

        if base_cmd[0] == "nook":
            direct = nook_func(base_cmd)

        elif base_cmd[0] == "hop":
            direct = hop_func(base_cmd)

        elif base_cmd[0] == "spot":
            if bc > 1: direct.location = base_cmd[1]
            else: new_spot()
        
        elif base_cmd[0] == "back":
            for t in reversed(range(spot_count)):
                if directive(command=command.index('back'),location='spot'+str(t)) not in dataset:
                    direct = directive(command=command.index('back'),location='spot'+str(t))
                    break

        elif base_cmd[1] not in nooks and base_cmd[1].isnumeric():
            dataset.append(["nook", "int", "t" + str(nook_count)])
            base_cmd.insert(1,"t"+str(nook_count))
            nooks.append("t"+str(nook_count))
            nook_count += 1

        elif len(base_cmd) == 3:
            base_cmd.insert(1,base_cmd[1])

        """
        elif base_cmd[0] == "friend":
            with open(base_cmd[1],'r') as f:
                d = pseudo(f.readlines(),header=base_cmd[1][:base_cmd[1].find('.')])
                dataset.append(d)
            return None
        """  

    return direct

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
        # print(base_cmd)
        # base_cmd = split_complex(base_cmd,header=header)
        #print(spa + str(base_cmd))
        dataset.append(split_complex(base_cmd=base_cmd,header=header))

def pseudo(code,header=None):
    global dataset

    for c in code:
        if ';' in c:
            c = c[:c.find(';')]
        c = c.strip()
        if c != "":
            layer(depth=c,header=header)
    
    return dataset