def findThreeLargestNumbers(array):
    first = None
    second = None
    third = None

    for item in array:
        if third is None or item > third:
            first = second
            second = third
            third = item
        elif second is None or item > second:
            first = second
            second = item
        elif first is None or item > first:
            first = item
    return [first, second, third]


print(findThreeLargestNumbers(
    [55, 8, 7]))
