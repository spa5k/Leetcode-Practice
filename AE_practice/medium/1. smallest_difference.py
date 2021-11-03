def smallestDifference(arrayOne, arrayTwo):
    arrayOne.sort()
    arrayTwo.sort()

    idx1 = 0
    idx2 = 0
    smallest = float("inf")
    current = float("inf")

    smallest_pair = []

    while idx1 < len(arrayOne) and idx2 < len(arrayTwo):
        first_num = arrayOne[idx1]
        second_num = arrayTwo[idx2]

        if first_num == second_num:
            return[first_num, second_num]

        if first_num < second_num:
            current = second_num-first_num
            idx1 += 1
        else:
            current = first_num-second_num
            idx2 += 1

        if smallest > current:
            smallest = current
            smallest_pair = [first_num, second_num]
    return smallest_pair
