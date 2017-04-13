with open("Charades_v1_mapping.txt") as f:
    lines = f.read().splitlines()
verbs = ['v000','v001','v002','v003','v004','v005','v006','v007']
f = open("verbobject","w")
x = set()
for verb in verbs:
    f.write('{0} : '.format(verb))
    for line in lines:
        row = line.split(" ")
        if (row[2] == verb):
            f.write(' {0} ,'.format(row[1]))
            x.add(row[1])
    f.write('\n')
f.close()
f = open("objectverb","w")
for objct in x:
    f.write('{0} : '.format(objct))
    for line in lines:
        row = line.split(" ")
        if (row[1] == objct):
            f.write(' {0} ,'.format(row[2]))
    f.write('\n')
f.close()
