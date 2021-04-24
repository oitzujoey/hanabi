import os, pprint, re, time

consts = {}

def rec_proc(data):
    in_type     = ''
    const       = ''
    in_f        = 0
    d           = 0
    stop_at     = 0
    while d < len(data):
        da      = data[d].replace('\r','').replace('\n','')
        args    = re.split('[ \t]',da)
        com     = re.split('[ #]',da)
        if com != ['']:
            command = [t for t in com if t != ''][0]
        else:
            command = ''
        spacing = com.index(command) - 1

        if command.startswith("if") and in_f == 0:
            in_type     = command
            from_l      = d
            stop_at     = spacing
            in_f        = 1
            const      = ' '.join(com[spacing+2:])

        if in_f == 0:

            if command == "define":
                if len(args) == 2:
                    consts[args[1]] = None
                else:
                    consts[args[1]] = args[2]
                del data[d]
                d -= 1

            if command == "include":
                print(args)
                f_name = '/usr/include/'+args[-1][1:-1] if args[-1][0] == '<' else './'+args[-1][1:-1]
                if os.path.exists(f_name):
                    with open(f_name) as s:
                        del data[d]

                        for ss in rec_proc(s.readlines()):
                            data.insert(d,ss)
                else:
                    del data[d]
            
        if command.startswith("else") and in_f == 1 and stop_at == spacing:
            data.insert(d,'#' + ''.join([' ' for t in range(spacing)]) + 'endif')
            data[d+1] = '#' + ''.join([' ' for t in range(spacing)]) + (
                'ifndef'    if in_type == 'ifdef'   else
                'ifdef'     if in_type == 'ifndef'  else
                'if'
            ) + ' ' + const
            command = 'endif'
            in_f = 0

        if command.startswith("endif"):
            if stop_at == spacing:
                if in_type == 'ifdef':
                    if const in consts.keys():
                        del data[d]
                        del data[from_l]
                        d = from_l
                    else:
                        del data[from_l:d+1]
                        d       = from_l - 1
                        in_f    = 0
                        in_type = ''

                elif in_type == 'ifndef':
                    if const not in consts.keys():
                        del data[d]
                        del data[from_l]
                        d = from_l
                    else:
                        del data[from_l:d+1]
                        d       = from_l - 1
                        in_f    = 0
                        in_type = ''


        """
                print(da)
        print('...')
        time.sleep(0.5)
        
        pprint.pprint(data)
        print('\n')
        """



        d += 1
    return data

with open('sample.c') as f:
    data = rec_proc(f.readlines())

with open('output.c', 'w') as output:
    output.writelines(data)
    pprint.pprint(data)

pprint.pprint(consts)

"""
        lev = 1
        i = d + 1
        print(str(d) + '\t' + str(data[d]))
        while i < range(len(data)-1) and lev > 0:
            if data[i] == "#ifndef":
                lev += 1
            elif data[i] == "#endif":
                lev -= 1
            print('\t' + str(data[i]) + '\t' + str(lev))
            i += 1
        pprint.pprint(data[d+1:i-1])
"""