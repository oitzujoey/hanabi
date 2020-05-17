import os, pprint, re, time

source = []
consts = {}

def rec_proc(data):
    d = 0
    while d < len(data):
        da = data[d].replace('\r','').replace('\n','')
        args = re.split('[ \t]',da)
        print('\n')
        print(da + '\t\t' + str(d))
        time.sleep(0.5)

        if len(da) > 0 and da[0] == "#":
            com = re.split('[ #]',args[0])

            if com[-1] == "include":
                fname = args[1][1:-1]
                if os.path.exists('/usr/include/'+fname):
                    with open('/usr/include/'+fname) as s:
                        data.pop(d)

                        for ss in rec_proc(s.readlines()):
                            data.insert(d,ss)
                            d += 1
                else:
                    del data[d]
            
            elif com[-1].startswith("if"):
                el = 0
                lev = 1
                i = d + 1
                while i < range(len(data)) and lev > 0:
                    com_2 = re.split('[ #]',data[i])

                    if data[i].startswith("#"):
                        if com_2[-1].startswith("if"):
                            lev += 1
                        elif com_2[-1].startswith("endif"):
                            lev -= 1
                        elif com_2[-1].startswith("else") and lev == 1:
                            if com[-1] == "ifndef":
                                comm = 'ifdef'
                            elif com[-1] == 'ifdef':
                                comm = 'ifndef'
                            else:
                                comm = 'if not'
                            data.insert(i,'#endif')
                            data[i+1] = '#' + comm + ' ' + ('' if len(args) == 1 else ' '.join(args[1:]))
                            lev -= 1
                            d -= 1
                            el = 1
                    i += 1
                if com[-1] == "ifndef":
                    if args[1] in consts:
                        del data[d:i]
                        d += 1
                        pprint.pprint(data)
                    else:
                        d += 1
                        del data[i-1]
                        del data[d]
                        pprint.pprint(data)
                elif com[-1] == "ifdef":
                    if args[1] in consts:
                        d += 1
                        del data[i-1]
                        del data[d]
                        pprint.pprint(data)
                    else:
                        del data[d:i]
                        d += 1
                        pprint.pprint(data)
                else:
                    d += 1
                if el == 1:
                    d -= 1

            elif com[-1] == "define":
                if len(args) == 2:
                    consts[args[1]] = None
                else:
                    consts[args[1]] = args[2]
                del data[d]

            else:
                d += 1
        
        else:
            d += 1

        #print(str(d) + '\t' + str(len(data)))
    return data

with open('simple.c') as f:
    data = rec_proc(f.readlines())

pprint.pprint(consts)

with open('output.c', 'w') as output:
    output.writelines(data)
    pprint.pprint(data)