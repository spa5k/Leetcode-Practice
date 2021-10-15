#  For Loop
#  O(n) time | O(1) space


def isValidSubsequence(array, sequence):
    current_index = 0
    for num in array:
        if current_index == len(sequence):
            break

        if sequence[current_index] == num:
            current_index += 1

    return current_index == len(sequence)
