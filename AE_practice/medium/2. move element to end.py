def moveElementToEnd(array, toMove):
    right = len(array)-1
    left = 0
    while left < right:
        num = array[left]

        if num == toMove:
            temp = array[right]
            if array[right] == toMove:
                right -= 1
                continue
            array[right] = num
            array[left] = temp
            right -= 1
        left += 1
    return array
