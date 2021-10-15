def sortedSquaredArray(array):
    sorted_squares = [0 for _ in array]
    smaller_value_idx = 0
    largest_value_idx = len(array)-1

    for idx in reversed(range(len(array))):
        smaller_value = array[smaller_value_idx]
        larger_value = array[largest_value_idx]

        if abs(smaller_value) > abs(larger_value):
            sorted_squares[idx] = smaller_value*smaller_value
            smaller_value_idx += 1
        else:
            sorted_squares[idx] = larger_value*larger_value
            largest_value_idx -= 1
    return sorted_squares
