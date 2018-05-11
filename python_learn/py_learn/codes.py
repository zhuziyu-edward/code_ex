def find_uniq(arr):    #从序列中找一个不一样的
    a, b = set(arr)
    return a if arr.count(a) == 1 else b

def gimme(inputArray):
    return inputArray.index(sorted(inputArray)[int(len(inputArray) / 2)])



def dirReduc(plan):
    opposite = {'NORTH': 'SOUTH', 'EAST': 'WEST', 'SOUTH': 'NORTH', 'WEST': 'EAST'}
    new_plan = []
    for d in plan:
        if new_plan and new_plan[-1] == opposite[d]:
            new_plan.pop()
        else:
            new_plan.append(d)
    return new_plan