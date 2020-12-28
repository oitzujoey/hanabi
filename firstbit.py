import pprint

nook = []
context = ""

data = """
nook msg "Testing this out"
nook x
spot
    1 +
    leaveon 10
    back
say
"""

"""
dataset = []

# Parse through code
def parse(d, dataset=dataset):
    cmd = []
    d = d.strip()

    is_data = False
    f = 0
    t = 0
    dn = 0
    rr = len(d)
    while dn < rr:
        dd = d[dn]
        t += 1

        if dd in ['"']:
            is_data = not is_data

        if not is_data:
            if dd in ["("]:
                end_loc = d.find(")",dn)
                ds = d[dn+1:end_loc]
                dataset.append(parse(ds))
                d = d[:dn] + (d[end_loc+2:] if end_loc < len(d) else [])

            elif dd in [' ']:
                cmd.append(d[f:t-1])
                f = t

            elif t == len(d):
                cmd.append(d[f:t])

        dn += 1
        rr = len(d)
    return cmd

for d in data.split('\n'):
    cmd = parse(d)
    if cmd != []:
        dataset.append(cmd)

pprint.pprint(dataset)
"""

depth = "12 (+ 5 (+ 6 (3)) 2) 1 6 (7 (9))"

def valuify(value):
    if value.isnumeric():
        return int(value)
    else:
        return value

dataset = []
command = ['+', '-', 'nook']
nooks = ['x']

def layer(depth,dataset=dataset,layers=0):
    start = 0
    end = 0
    in_l = 0
    internal_layers = layers

    # Handle recursion in parenthesis
    d = 0
    length = len(depth)
    while d < length:
        char = depth[d]

        if char == "(":
            if in_l == 0:
                start = d + 1
            in_l += 1

        elif char == ")":
            end = d
            in_l -= 1
            if in_l == 0 and start < end:
                #dataset.append("push c")
                internal_layers += 1
                layer(depth=depth[start:end],dataset=dataset,layers=internal_layers)
                depth = depth[0:start-1] + 'link' + str(len(dataset)) + depth[end+1:]
                end = start
                d = start

        d += 1
        length = len(depth)

    d_spac = depth.split(' ')

    if d_spac[0] not in command:
        d_spac.insert(0,"+")
    if d_spac[1] not in nook:
        d_spac.insert(1,"c")

    dataset.append(' '.join(d_spac))

    #for t in range(internal_layers - layers):
    #    dataset.append('pull c')

layer(depth=depth,dataset=dataset)
pprint.pprint(dataset)

"""
    # Handle actual calculations
    values = []
    d = 0
    length = len(depth)

    while d < length:
        char = depth[d]
        if char == " ":
            values.append(valuify(depth[0:d]))
            depth = depth[d+1:]

        d += 1
        length = len(depth)

    values.append(valuify(depth))
    return str(values[0])
"""