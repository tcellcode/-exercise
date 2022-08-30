# can flatten irregular list
def flatten(L):
    for item in L:
        try:
            yield from flatten(item)
        except TypeError:
            yield item
# answeres in Stack Overflow by @dansalmo
# link: https://stackoverflow.com/questions/2158395/flatten-an-irregular-list-of-lists
