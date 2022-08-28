# can flatten irregular list
def flatten(l):
    if len(l) == 0:
        return l
    if type(l[0]) in (list, tuple, set):
        return flatten(l[0]) + flatten(l[1:])
    return l[:1] + flatten(l[1:])
