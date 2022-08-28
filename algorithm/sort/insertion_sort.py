# reverse = True : sort from greatest to least
def insertion_sort(arr, reverse=False):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            state = arr[j] > arr[j-1] if reverse else arr[j] < arr[j-1]
            if state:
                arr[j], arr[j-1] = arr[j-1], arr[j]
            else: break
                
    return arr
