import pprint, pseudo

with open('dump.hana') as f:
    vars = pseudo.pseudo(f.readlines())

final = []
for v in vars:
    pseudo.directive.output(v)