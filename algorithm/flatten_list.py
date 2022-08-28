# can flatten irregular list
def flatten(L):
    for item in L:
        try:
            yield from flatten(item)
        except TypeError:
            yield item
