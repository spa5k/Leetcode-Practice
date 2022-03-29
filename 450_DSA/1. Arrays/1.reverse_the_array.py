# Reverse the array.
def reverse_the_array(arr):
    # First we will take first value out of the array.
    for i in range(len(arr)-1):
        arr.append(arr[-2-i])
        del(arr[-3-i])
    return arr


print(reverse_the_array(
    [1, 2, 1, 2, 32, 31, 231, 23, 123, 123, -1, -234, 234, 123]))
