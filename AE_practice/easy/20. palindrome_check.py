
def palindrome_check(str):
    leftIdx = 0
    rightIdx = len(str)-1

    while leftIdx < rightIdx:
        if str[leftIdx] != str[rightIdx]:
            return False
        leftIdx += 1
        rightIdx -= 1

    return True


def middle_char(txt):
    return txt[(len(txt)-1)//2:(len(txt)+2)//2]


print(palindrome_check("babaa"))
