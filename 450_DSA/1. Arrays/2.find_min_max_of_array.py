from tkinter.messagebox import NO


def find_min_max(arr):
    if len(arr) < 2:
        return [arr[0]]

    if len(arr) == 2:
        min1 = max(arr[0], arr[1])
        max2 = min(arr[0], arr[1])
        return [m1, m2]

    min_1 = arr[0]
    max_1 = arr[1]

    for idx, item in enumerate(arr):
        if item <min_1:
            min_1=item
        elif item>max_1:
          max_1=item

    return [min_1, max_1]


print(find_min_max([1, 2, 3, 4, 5, 6, 61, 9, -1]))
