import pprint

nook = []
context = ""

data = """
nook msg "Testing this out"
nook msg (test variable) bit"
nook x
spot
    1 +
    leaveon 10
    back
say
"""

dataset = []

# Parse through code
def parse(d):
    cmd = []
    d = d.strip()

    is_data = False
    f = 0
    t = 0
    dn = 0
    rr = len(d)
    if dn < rr:
        dd = d[dn]
        t += 1
        if dd in ['"']:
            is_data = not is_data

        if not is_data:
            if dd in ["("]:
                end_loc = d.find(")",dn)
                ds = d[dn+1:end_loc]
                print(ds)
                d = d[:dn] + (d[end_loc+1] if end_loc < len(d) else [])
                
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