def bubbleSort(array):
    is_sorted = False
    counter = 0

    while not is_sorted:
        is_sorted = True

        for i in range(len(array)-1-counter):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                is_sorted = False
        counter += 1
    return array
